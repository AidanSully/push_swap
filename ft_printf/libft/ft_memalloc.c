/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:29:03 by awehlbur       #+#    #+#                */
/*   Updated: 2019/07/11 17:12:48 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	s = (char*)malloc(sizeof(char) * size);
	if (!s)
		return (NULL);
	if (s != NULL)
		ft_memset(s, '\0', size);
	return (s);
}
