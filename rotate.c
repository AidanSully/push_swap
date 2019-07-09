/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:31:50 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 15:34:46 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rot_a(int len, int pos, char **rot_a)
{
	if (pos > len / 2)
	{
		*rot_a = ft_strcpy(*rot_a, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*rot_a = ft_strcpy(*rot_a, "ra");
	return (pos);
}

int		rot_b(int len, int pos, char **rot_b)
{
	if (pos > len / 2)
	{
		*rot_b = ft_strcpy(*rot_b, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*rot_b = ft_strcpy(*rot_b, "rb");
	return (pos);
}

void	rot_to_smallest_a(t_stack *stack)
{
	int min_index;

	min_index = find_min_index(stack->a, stack->size_a);
	if (min_index <= stack->size_a / 2)
	{
		while (min_index--)
			ra(stack);
	}
	else
	{
		while ((stack->size_a - min_index) > 0)
		{
			rra(stack);
			min_index++;
		}
	}
}
