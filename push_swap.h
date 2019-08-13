/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:11:27 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/08 18:18:26 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define NORMAL "\033[0m"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_stack
{
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
	int			ops;
	int			print_ops;
	int			colour;
	int			print;
	int			total;
	int			slow;
}				t_stack;

typedef struct	s_moves
{
	int			a;
	int			b;
	int			common;
	int			total;
	char		*rot_a;
	char		*rot_b;
	char		*rot_common;
}				t_moves;

/*
**  functions in read.c
*/

void			get_options(int *ac, char ***av, t_stack *stack, int program);
void			error(t_stack *stack, int usage, char *message);
t_stack			*get_args(int ac, char **av, t_stack *stack, int option);

/*
**	functions in stack.c
*/

void			free_stack(t_stack *stack);
void			free_moves(t_moves *moves);
int				sorted(int *stack, int len);
int				reverse_sort(int *stack, int len);
void			init(t_stack *stack, int ac, int option);

/*
**	functions in print.c
*/

void			init_print(t_stack *stack);
void			final_print(t_stack *stack);
void			info_print(void);
void			usage_print(int option);
void			stack_print(t_stack *stack);

/*
**	functions in swap.c
*/

void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack);

/*
**	functions in push.c
*/

void			pa(t_stack *stack);
void			pb(t_stack *stack);

/*
**	functions in rot.c
*/

void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stack);

/*
**	functions in revrot.c
*/

void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stack);

/*
** functions in helper.c
*/

int				find_min_el(int *stack, int stack_len);
int				find_max_el(int *stack, int stack_len);
int				find_min_index(int *stack, int len);
int				find_max_index(int *stack, int len);

/*
** functions in sort.c
*/

void			sort(t_stack *stack);

/*
** functions in sort_big.c
*/

void			big_sort(t_stack *stack);

/*
** functions in findawae.c
*/

t_moves			*dawae(t_stack *stack);

/*
** functions in find_rotate.c
*/

void			rot_to_smallest_a(t_stack *stack);
int				rot_a(int len, int pos, char **rot_a);
int				rot_b(int len, int pos, char **rot_b);

#endif
