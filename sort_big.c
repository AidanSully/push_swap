/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:21:29 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 15:53:24 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_b(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->size_a > 2)
	{
		i = find_min_el(stack->a, stack->size_a);
		if (i == 0)
			pb(stack);
		else if (i <= stack->size_a / 2)
			ra(stack);
		else if (i > stack->size_a / 2)
			rra(stack);
	}
}

static int	find_apos(int *stack, int len, int elem, char **rot_type)
{
	int i;
	int place;

	i = 0;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max_el(stack, len)]
	|| elem < stack[find_min_el(stack, len)])
		place = find_min_el(stack, len);
	else
		while (i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1]) ||
			(i + 1 == len && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (rot_a(len, place, rot_type));
}

static void	insert_a(t_stack *stack)
{
	int				rot;
	char			*rot_type;

	rot = 0;
	rot_type = ft_strnew(3);
	while (stack->size_b)
	{
		rot = find_apos(stack->a, stack->size_a, stack->b[0], &rot_type);
		while (rot > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				ra(stack);
			else
				rra(stack);
			rot--;
		}
		pa(stack);
	}
	rot_to_smallest_a(stack);
	free(rot_type);
}

static void	apply(t_moves *best_move, t_stack *stack)
{
	while (best_move->a)
	{
		if (ft_strequ(best_move->rot_a, "ra"))
			ra(stack);
		else
			rra(stack);
		best_move->a--;
	}
	while (best_move->b)
	{
		if (ft_strequ(best_move->rot_b, "rb"))
			rb(stack);
		else
			rrb(stack);
		best_move->b--;
	}
}

void		big_sort(t_stack *stack)
{
	t_moves *best_move;
	int		len;

	len = (stack->size_a > 200) ? 30 : 2;
	while (stack->size_b != 2)
		pb(stack);
	while (stack->size_a > len)
	{
		best_move = dawae(stack);
		while (best_move->common)
		{
			if (ft_strequ(best_move->rot_common, "rr"))
				rr(stack);
			else
				rrr(stack);
			best_move->common--;
		}
		apply(best_move, stack);
		pb(stack);
		free_moves(best_move);
	}
	insert_b(stack);
	insert_a(stack);
}
