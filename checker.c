/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 13:44:41 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 15:53:44 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_op(t_stack *stack, char *op)
{
	if (ft_strequ(op, "sa"))
		sa(stack);
	else if (ft_strequ(op, "sb"))
		sb(stack);
	else if (ft_strequ(op, "ss"))
		ss(stack);
	else if (ft_strequ(op, "pa"))
		pa(stack);
	else if (ft_strequ(op, "pb"))
		pb(stack);
	else if (ft_strequ(op, "ra"))
		ra(stack);
	else if (ft_strequ(op, "rb"))
		rb(stack);
	else if (ft_strequ(op, "rr"))
		rr(stack);
	else if (ft_strequ(op, "rra"))
		rra(stack);
	else if (ft_strequ(op, "rrb"))
		rrb(stack);
	else if (ft_strequ(op, "rrr"))
		rrr(stack);
	else
		return (-1);
	return (0);
}

void		do_ops(t_stack *stack)
{
	char	*op;
	int		ret;

	init_print(stack);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &op);
		if (!op)
			break ;
		if (get_op(stack, op))
		{
			free(op);
			error(stack, 0);
		}
		free(op);
		op = NULL;
	}
	final_print(stack);
	free(op);
}

int			main(int ac, char **av)
{
	t_stack		*stack;

	ac--;
	(ac == 1) ? exit(0) : av++;
	stack = (t_stack*)malloc(sizeof(t_stack));
	get_options(&ac, &av, stack);
	if (ac == 1)
	{
		av = ft_strsplit(av[0], ' ');
		ac = 0;
		while (av && av[ac])
			ac++;
		if (ac == 0)
			error(stack, 0);
	}
	init(stack, ac, 1);
	stack = get_args(ac, av, stack);
	if (!(sorted(stack->a, stack->size_a)))
		do_ops(stack);
	if (sorted(stack->a, stack->size_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack);
	return (0);
}
