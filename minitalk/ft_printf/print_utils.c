/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:45:24 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/28 00:50:01 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
	{
		a++;
	}
	return (a);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s)
		return (0);
	while (i < ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*strrev(char *c)
{
	int		i;
	int		j;
	char	temp;

	j = ft_strlen(c) - 1;
	i = 0;
	temp = 0;
	while (i < j)
	{
		temp = c [i];
		c[i] = c[j];
		c[j] = temp;
		i++;
		j--;
	}
	return (c);
}
