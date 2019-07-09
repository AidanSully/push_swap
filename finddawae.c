/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finddawae.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:27:24 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 15:43:17 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_bpos(int *stack, int len, int el, char **rot_type)
{
	int		i;
	int		place;

	i = 0;
	place = 0;
	if (len == 2 && el > stack[0] && el < stack[len - 1])
		place = 0;
	else if (len == 2 && el < stack[0] && el > stack[len - 1])
		place = 1;
	else if (el > stack[find_max_el(stack, len)] ||
	el < stack[find_min_el(stack, len)])
		place = find_max_el(stack, len);
	else
		while (i < len)
		{
			if (el < stack[i] && ((i + 1 < len && el > stack[i + 1]) ||
			(i + 1 == len && el > stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (rot_b(len, place, rot_type));
}

static int		find_common(t_moves *moves)
{
	int		common;

	common = 0;
	if ((ft_strequ(moves->rot_a, "rra")
	&& (ft_strequ(moves->rot_b, "rrb")))
	|| (ft_strequ(moves->rot_a, "ra")
	&& (ft_strequ(moves->rot_b, "rb"))))
	{
		common = (moves->a > moves->b ? moves->b : moves->a);
		if (common)
		{
			moves->rot_common = ft_strcpy(moves->rot_common, moves->rot_a);
			moves->rot_common[ft_strlen(moves->rot_common) - 1] = 'r';
			moves->b -= common;
			moves->a -= common;
		}
	}
	return (common);
}

static t_moves	*calc_moves(t_stack *stack, int pos)
{
	t_moves *moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->rot_a = ft_strnew(3);
	moves->rot_b = ft_strnew(3);
	moves->rot_common = ft_strnew(3);
	moves->a = rot_a(stack->size_b, pos, &(moves->rot_a));
	moves->b = find_bpos(stack->b, stack->size_b,
	stack->a[pos], &(moves->rot_b));
	moves->common = find_common(moves);
	moves->total = moves->a + moves->b + moves->common + 1;
	return (moves);
}

t_moves			*dawae(t_stack *stack)
{
	int			i;
	t_moves		*best_move;
	t_moves		*moves;

	i = 0;
	while (i < stack->size_b)
	{
		moves = calc_moves(stack, i);
		if (i == 0)
			best_move = moves;
		else if (best_move->total > moves->total)
		{
			free_moves(best_move);
			best_move = moves;
		}
		else
			free_moves(moves);
		i++;
	}
	return (best_move);
}
