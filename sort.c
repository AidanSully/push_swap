/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:18:15 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/08 15:46:07 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_small(t_stack *stack)
{
	int max;

	if (stack->size_a == 1)
		return ;
	if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
		return ;
	}
	else if (stack->size_a == 3)
	{
		max = find_max_el(stack->a, stack->size_a);
		if (max == 0)
			ra(stack);
		if (max == 1)
			rra(stack);
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
}

void		sort(t_stack *stack)
{
	if (sorted(stack->a, stack->size_a) && stack->size_b == 0)
		return ;
	init_print(stack);
	if (stack->size_a <= 3)
		return (sort_small(stack));
	else
		big_sort(stack);
	final_print(stack);
}
