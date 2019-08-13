/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:06:39 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/13 19:21:15 by asulliva      ########   odam.nl         */
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

t_stack			*get_args(int ac, char **av, t_stack *stack, int option)
{
	int		i;

	i = 0;
	init(stack, ac, option);
	while (i < ac)
	{
		if (validate_args(av, av[i], i + 1))
			stack->a[i] = ft_atoi(av[i]);
		else
			error(stack, option, "Invalid input");
		i++;
	}
	return (stack);
}

static void		small_error(t_stack *stack, int program)
{
	free(stack);
	usage_print(program);
	exit(0);
}

static void		init_options(t_stack *stack)
{
	stack->total = 0;
	stack->colour = 0;
	stack->print = 0;
	stack->slow = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->a = NULL;
	stack->b = NULL;
}

/*
**	program == 1 push_swap
*/

void			get_options(int *ac, char ***av, t_stack *stack, int program)
{
	int i;

	i = 0;
	init_options(stack);
	while (i < *ac && *((*av)[i]) == '-')
	{
		if (*((*av)[i]) == '-' && ft_atoi(&(*((*av))[i])) < 0)
			break ;
		if (ft_strequ((*av)[i], "-v"))
			stack->print = 1;
		else if (ft_strequ((*av)[i], "-t"))
			stack->total = 1;
		else if (ft_strequ((*av)[i], "-c"))
			stack->colour = 1;
		else if (ft_strequ((*av)[i], "-vs") && program == 1)
		{
			stack->slow = 1;
			stack->print = 1;
		}
		else
			small_error(stack, program);
		i++;
	}
	*ac -= i;
	*av += i;
}
