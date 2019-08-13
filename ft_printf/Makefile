# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/25 13:40:40 by asulliva       #+#    #+#                 #
#    Updated: 2019/07/19 14:49:47 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/

SRCS = srcs/precision.c srcs/width.c srcs/extra.c srcs/modifier.c \
srcs/conversion.c srcs/go_print.c \
srcs/handle_d.c srcs/handle_c.c srcs/ft_printf.c srcs/handle_s.c \
srcs/handle_modulo.c srcs/handle_p.c \
srcs/handle_f.c srcs/make_fstr.c srcs/handle_u.c srcs/handle_sx.c \
srcs/handle_o.c srcs/defines.c \
srcs/handle_f1.c srcs/handle_o1.c srcs/handle_p1.c srcs/handle_s1.c \
srcs/handle_d1.c srcs/handle_d2.c srcs/handle_d3.c \

OBJS := precision.o width.o extra.o modifier.o conversion.o go_print.o \
handle_d.o handle_c.o ft_printf.o handle_s.o handle_modulo.o handle_p.o \
handle_f.o make_fstr.o handle_u.o handle_sx.o handle_o.o defines.o \
handle_f1.o handle_o1.o handle_p1.o handle_s1.o handle_d1.o handle_d2.o \
handle_d3.o

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc $(CFLAGS) -c $(SRCS) -I .
	@ar rcs $(NAME) $(OBJS) ./libft/*.o
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all
