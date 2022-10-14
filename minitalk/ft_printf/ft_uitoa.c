/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 02:20:46 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/28 02:34:53 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*uia(unsigned int n, char *str)
{
	unsigned int	i;
	unsigned int	temp;

	i = 0;
	temp = n;
	while (temp > 0)
	{
		str[i] = temp % 10 + 48;
		temp = temp / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	calculateallocate(unsigned int n)
{
	size_t			i;
	unsigned int	temp;

	i = 0;
	temp = n;
	while (temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (calculateallocate(n) + 1));
	if (!str)
		return (0);
	str = uia(n, str);
	str = strrev(str);
	return (str);
}
