/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:06:39 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 15:39:49 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		validate_args(char **av, char *arg, int start)
{
	int		i;

	i = 0;
	while (*arg && arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (0);
		i++;
	}
	if (ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN)
		return (0);
	while (av[start] && av && arg)
	{
		if (ft_strequ(av[start], arg))
			return (0);
		start++;
	}
	return (1);
}

void			error(t_stack *stack, int usage)
{
	free_stack(stack);
	if (usage == 1)
		ft_printf("Usage:\n./push_swap [int array]\nOptions:\n[-v -t -c]\n");
	ft_printf("Error\n");
	exit(0);
}

t_stack			*get_args(int ac, char **av, t_stack *stack)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		if (validate_args(av, av[i], i + 1) == 1)
			stack->a[i] = ft_atoi(av[i]);
		else
			error(stack, 0);
		i++;
	}
	return (stack);
}

void			get_options(int *ac, char ***av, t_stack *stack)
{
	int i;

	i = 0;
	stack->total = 0;
	stack->colour = 0;
	stack->print = 0;
	while (i < *ac && *((*av)[i]) == '-')
	{
		if (ft_strequ((*av)[i], "-v"))
			stack->print = 1;
		else if (ft_strequ((*av)[i], "-t"))
			stack->total = 1;
		else if (ft_strequ((*av)[i], "-c"))
			stack->colour = 1;
		else
			error(stack, 1);
		i++;
	}
	*ac -= i;
	*av += i;
}
