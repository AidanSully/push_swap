/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rot.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 18:14:36 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/13 19:32:45 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->size_a == 0)
		error(stack, 0, "No elements in stack a");
	i = 1;
	tmp = stack->a[0];
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	if (stack->print_ops)
		ft_putstr("ra\n");
	stack->ops++;
	if (stack->print)
		stack_print(stack);
}

void		rb(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->size_b == 0)
		error(stack, 0, "No elements in stack b");
	i = 1;
	tmp = stack->b[0];
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	if (stack->print_ops)
		ft_putstr("rb\n");
	stack->ops++;
	if (stack->print)
		stack_print(stack);
}

void		rr(t_stack *stack)
{
	int tmp_ops;
	int tmp_print;

	tmp_print = stack->print;
	tmp_ops = stack->print_ops;
	stack->print_ops = 0;
	stack->print = 0;
	ra(stack);
	rb(stack);
	stack->print_ops = tmp_ops;
	stack->print = tmp_print;
	if (stack->print_ops)
		ft_putstr("rr\n");
	if (stack->print)
		stack_print(stack);
	stack->ops--;
}
