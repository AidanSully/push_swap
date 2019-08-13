/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:15:25 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/13 19:29:39 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check(int ac)
{
	if (ac - 1 == 0)
		usage_print(1);
	return (ac - 1);
}

int				main(int ac, char **av)
{
	t_stack		*stack;

	ac = check(ac);
	av++;
	stack = (t_stack*)malloc(sizeof(t_stack));
	get_options(&ac, &av, stack, 1);
	if (ac == 1)
	{
		av = ft_strsplit(av[0], ' ');
		ac = 0;
		while (av && av[ac])
			ac++;
		if (ac == 0)
			error(stack, 1, "Invalid input");
	}
	stack = get_args(ac, av, stack, 1);
	sort(stack);
	free_stack(stack);
	return (0);
}
