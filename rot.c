/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rot.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 18:14:36 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 15:51:18 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->size_a == 0)
		error(stack, 0);
	i = 1;
	tmp = stack->a[0];
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	stack->print_ops ? ft_printf("ra\n") : 0;
	if (stack->print)
	{
		ft_printf("A: ");
		ft_print_int_array(stack->a, stack->size_a);
		if (stack->size_b)
		{
			ft_printf("B: ");
			ft_print_int_array(stack->b, stack->size_b);
		}
	}
	stack->ops++;
}

void		rb(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->size_b == 0)
		error(stack, 0);
	i = 1;
	tmp = stack->b[0];
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	stack->print_ops ? ft_printf("rb\n") : 0;
	if (stack->print)
	{
		ft_printf("A: ");
		ft_print_int_array(stack->a, stack->size_a);
		if (stack->size_b)
		{
			ft_printf("B: ");
			ft_print_int_array(stack->b, stack->size_b);
		}
	}
	stack->ops++;
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
	stack->print_ops ? ft_printf("rr\n") : 0;
	if (stack->print)
	{
		ft_printf("A: ");
		ft_print_int_array(stack->a, stack->size_a);
		if (stack->size_b)
		{
			ft_printf("B: ");
			ft_print_int_array(stack->b, stack->size_b);
		}
	}
	stack->ops--;
}
