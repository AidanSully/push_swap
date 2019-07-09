/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 15:20:43 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 14:45:19 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_print(t_stack *stack)
{
	if (stack->print)
	{
		stack->colour ? ft_putstr(RED) : 0;
		ft_printf("Initial array: ");
		ft_print_int_array(stack->a, stack->size_a);
		stack->colour ? ft_putstr(GREEN) : 0;
	}
}

void		final_print(t_stack *stack)
{
	if (stack->print)
	{
		stack->colour ? ft_putstr(RED) : 0;
		ft_printf("Sorted array: ");
		ft_print_int_array(stack->a, stack->size_a);
	}
	if (stack->total)
	{
		stack->colour ? ft_putstr(YELLOW) : 0;
		ft_printf("Total operations: %d\n", stack->ops);
		stack->colour ? ft_putstr(NORMAL) : 0;
	}
}
