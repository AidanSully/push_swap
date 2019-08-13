/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:49:50 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/13 19:37:25 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa(t_stack *stack)
{
	int i;

	if (stack->size_b == 0)
		error(stack, 2, "No element in stack b");
	i = stack->size_a;
	while (i > 0)
	{
		i--;
		stack->a[i + 1] = stack->a[i];
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i <= stack->size_b)
	{
		i++;
		stack->b[i - 1] = stack->b[i];
	}
	stack->size_a++;
	stack->size_b--;
	if (stack->print_ops)
		ft_putstr("pa\n");
	stack->ops++;
	if (stack->print)
		stack_print(stack);
}

void		pb(t_stack *stack)
{
	int i;

	if (stack->size_a == 0)
		error(stack, 2, "No element in stack a");
	i = stack->size_b;
	while (i > 0)
	{
		i--;
		stack->b[i + 1] = stack->b[i];
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i <= stack->size_a - 1)
	{
		i++;
		stack->a[i - 1] = stack->a[i];
	}
	stack->size_b++;
	stack->size_a--;
	if (stack->print_ops)
		ft_putstr("pb\n");
	stack->ops++;
	if (stack->print)
		stack_print(stack);
}

void		error(t_stack *stack, int usage, char *message)
{
	free_stack(stack);
	if (stack->slow)
		ft_printf("%d\n", stack->slow);
	if (usage == 1)
		ft_printf("Usage:\n./push_swap [-v[s] -t -c][array (no doubles)]\n");
	if (usage == 0)
		ft_printf("Usage:\n./checker [-v -t -c][array (no doubles)]\n");
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}
