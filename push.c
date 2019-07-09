/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:49:50 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 15:50:54 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa(t_stack *stack)
{
	int i;

	if (stack->size_b == 0)
		error(stack, 0);
	i = stack->size_a;
	while (i-- > 0)
		stack->a[i + 1] = stack->a[i];
	stack->a[0] = stack->b[0];
	i = 0;
	while (i++ <= stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->size_a++;
	stack->size_b--;
	stack->print_ops ? ft_printf("pa\n") : 0;
	if (stack->print == 1)
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

void		pb(t_stack *stack)
{
	int i;

	if (stack->size_a == 0)
		error(stack, 0);
	i = stack->size_b;
	while (i-- > 0)
		stack->b[i + 1] = stack->b[i];
	stack->b[0] = stack->a[0];
	i = 0;
	while (i++ <= stack->size_a - 1)
		stack->a[i - 1] = stack->a[i];
	stack->size_b++;
	stack->size_a--;
	stack->print_ops ? ft_printf("pb\n") : 0;
	if (stack->print == 1)
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
