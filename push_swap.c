/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:15:25 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 16:12:50 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int ac, char **av)
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
	init(stack, ac, 0);
	stack = get_args(ac, av, stack);
	sort(stack);
	free_stack(stack);
	return (0);
}
