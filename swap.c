/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 18:13:35 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/13 19:00:11 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_stack *stack)
{
	int tmp;

	if (stack->size_a < 2)
		error(stack, 0, "Not enough elements in stack a to swap");
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	stack->print_ops ? ft_putstr("sa\n") : 0;
	stack->ops++;
	if (stack->print)
		stack_print(stack);
}

void		sb(t_stack *stack)
{
	int tmp;

	if (stack->size_b < 2)
		error(stack, 0, "Not enough elements in stack b to swap");
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	stack->print_ops ? ft_putstr("sb\n") : 0;
	stack->ops++;
	if (stack->print)
		stack_print(stack);
}

void		ss(t_stack *stack)
{
	int tmp_ops;
	int tmp_print;

	tmp_print = stack->print;
	tmp_ops = stack->print_ops;
	stack->print_ops = 0;
	stack->print = 0;
	sa(stack);
	sb(stack);
	stack->print_ops = tmp_ops;
	stack->print = tmp_print;
	stack->print_ops ? ft_putstr("ss\n") : 0;
	if (stack->print)
		stack_print(stack);
	stack->ops--;
}
