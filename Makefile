# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/07/03 18:14:15 by asulliva       #+#    #+#                 #
#    Updated: 2019/07/09 15:37:52 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PUSHSWAP	= push_swap
CHECKER		= checker

.PHONY: all clean fclean re

CFLAGS 	= -Wall -Wextra -Werror -g

SRC1 	= push_swap.c read.c stack.c print.c swap.c push.c rot.c revrot.c \
sort.c helper.c sort_big.c finddawae.c rotate.c

SRC2 	= checker.c read.c stack.c print.c swap.c push.c rot.c revrot.c


RED		=	\033[0;31m
GREEN	=	\033[0;32m
NORMAL	=	\033[0m

OBJSFD 	= objects

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))
OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

INCLUDES 		= -I./includes
LIBFT_INCLUDES 	= -I./ft_printf/includes
LIB_BINARY		= -L./ft_printf -lft
LIBFT			= ft_printf/libft.a

$(LIBFT):
	@make -C ft_printf re

all: $(LIBFT) $(PUSHSWAP) $(CHECKER)

$(OBJSFD):
	@mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_INCLUDES) -c $< -o $@

$(PUSHSWAP): $(OBJS1) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NORMAL)"
	@gcc $(CFLAGS) $(OBJS1) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to use$(NORMAL)"

$(CHECKER): $(OBJS2) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NORMAL)"
	@gcc $(CFLAGS) $(OBJS2) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to use$(NORMAL)"

clean:
	@echo "$(RED)deleting object files...$(NORMAL)"
	@/bin/rm -f $(OBJS)
	@rm -rf $(OBJSFD)
	@make -C ./ft_printf clean

fclean: clean
	@echo "$(RED)deleting both executables...$(NORMAL)"
	@/bin/rm -f $(PUSHSWAP)
	@/bin/rm -f $(CHECKER)
	@make -C ./ft_printf fclean

re: fclean all
