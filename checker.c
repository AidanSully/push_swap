/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 13:44:41 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/13 19:43:46 by asulliva      ########   odam.nl         */
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
		return (1);
	return (0);
}

char		*trimnl(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}

void		do_ops(t_stack *stack)
{
	char	*ops;
	char	*buff;
	char	*temp;
	int		ret;

	init_print(stack);
	ret = 1;
	ops = ft_strnew(1);
	buff = ft_strnew(1);
	ft_putstr("Input instructions, finish with CTRL+D\n");
	while (ret > 0)
	{
		if (ft_strchr(ops, '\n'))
		{
			get_op(stack, trimnl(ops));
			ft_strclr(ops);
		}
		ret = read(0, buff, 1);
		temp = ops;
		ops = ft_strjoin(ops, buff);
		free(temp);
	}
	final_print(stack);
	free(buff);
	free(ops);
}

static int	check(int ac)
{
	if (ac - 1 == 0)
		usage_print(0);
	return (ac - 1);
}

int			main(int ac, char **av)
{
	t_stack	*stack;

	ac = check(ac);
	av++;
	stack = (t_stack*)malloc(sizeof(t_stack));
	get_options(&ac, &av, stack, 0);
	if (ac == 1)
	{
		av = ft_strsplit(av[0], ' ');
		ac = 0;
		while (av && av[ac])
			ac++;
		if (ac == 0)
			error(stack, 0, "Invalid input");
	}
	stack = get_args(ac, av, stack, 0);
	do_ops(stack);
	if (sorted(stack->a, stack->size_a) && stack->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack);
	return (0);
}
