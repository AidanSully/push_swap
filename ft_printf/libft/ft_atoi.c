/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:27:01 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:27:03 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int		ft_whitespace(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\v') || (c == '\n')\
	|| (c == '\r') || (c == '\f'))
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *s)
{
	int c;
	int i;
	int n;

	c = 0;
	i = 0;
	n = 0;
	while (((*s == '-' || *s == '+') && ft_isdigit(s[1]))
	|| ft_whitespace(*s))
	{
		if (*s == '-')
		{
			c = 1;
			if (!(ft_isdigit(s[1])))
				return (0);
		}
		s++;
	}
	while (s[i] != '\0' && ft_isdigit(s[i]))
		n = (n * 10) + (s[i++] - 48);
	if (c)
		n = -n;
	return (n);
}
