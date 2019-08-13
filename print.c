/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 15:20:43 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/13 19:37:39 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_print(t_stack *stack)
{
	if (stack->print == 1 || stack->print == 2)
	{
		stack->colour ? ft_putstr(RED) : 0;
		ft_printf("Initial array: ");
		ft_print_int_array(stack->a, stack->size_a);
		stack->colour ? ft_putstr(GREEN) : 0;
	}
}

void		final_print(t_stack *stack)
{
	if (stack->print == 1 || stack->print == 2)
	{
		stack->colour ? ft_putstr(RED) : 0;
		if (stack->size_a)
		{
			ft_printf("Final array A: ");
			ft_print_int_array(stack->a, stack->size_a);
		}
		if (stack->size_b)
		{
			ft_printf("Final array B: ");
			ft_print_int_array(stack->b, stack->size_b);
		}
	}
	if (stack->total)
	{
		stack->colour ? ft_putstr(YELLOW) : 0;
		ft_printf("Total operations: %d\n", stack->ops);
		stack->colour ? ft_putstr(NORMAL) : 0;
	}
}

void		usage_print(int option)
{
	if (option == 1)
		ft_printf("Usage:\n./push_swap [-v[s] -t -c][array (no doubles)]\n");
	if (option == 0)
		ft_printf("Usage:\n./checker [-v -t -c][array (no doubles)]\n");
	exit(0);
}

void		stack_print(t_stack *stack)
{
	if (stack->slow)
	{
		usleep(750000);
		system("clear");
	}
	ft_printf("A: ");
	ft_print_int_array(stack->a, stack->size_a);
	if (stack->size_b)
	{
		ft_printf("B: ");
		ft_print_int_array(stack->b, stack->size_b);
	}
	if (stack->slow)
	{
		ft_putstr(YELLOW);
		ft_printf("Total: %d\n", stack->ops);
		if (stack->colour)
			ft_putstr(GREEN);
		else
			ft_putstr(NORMAL);
	}
}
