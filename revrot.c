/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   revrot.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 18:15:41 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/13 19:32:16 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->size_a == 0)
		error(stack, 0, "No elements in stack a");
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	if (stack->print_ops)
		ft_putstr("rra\n");
	stack->ops++;
	if (stack->print)
		stack_print(stack);
}

void		rrb(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->size_b == 0)
		error(stack, 0, "No elements in stack b");
	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	if (stack->print_ops)
		ft_putstr("rrb\n");
	stack->ops++;
	if (stack->print)
		stack_print(stack);
}

void		rrr(t_stack *stack)
{
	int tmp_ops;
	int tmp_print;

	tmp_print = stack->print;
	tmp_ops = stack->print_ops;
	stack->print_ops = 0;
	stack->print = 0;
	rra(stack);
	rrb(stack);
	stack->print_ops = tmp_ops;
	stack->print = tmp_print;
	if (stack->print_ops)
		ft_putstr("rrr\n");
	if (stack->print)
		stack_print(stack);
	stack->ops--;
}
