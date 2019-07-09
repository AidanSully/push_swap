/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:12:06 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 15:34:57 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				sorted(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int				reverse_sort(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void			free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	stack = NULL;
}

void			free_moves(t_moves *moves)
{
	free(moves->rot_a);
	free(moves->rot_b);
	free(moves->rot_common);
	free(moves);
	moves = NULL;
}

void			init(t_stack *stack, int ac, int option)
{
	stack->a = (int*)malloc(sizeof(int) * ac);
	stack->b = (int*)ft_memalloc(sizeof(int) * ac);
	stack->size_a = ac;
	stack->size_b = 0;
	stack->ops = 0;
	stack->print_ops = (option == 1 ? 0 : 1);
}
