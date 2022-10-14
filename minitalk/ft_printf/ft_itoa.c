/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:27:25 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/28 00:51:44 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ia(int n, char *str)
{
	int	i;
	int	temp;

	i = 0;
	temp = n;
	if (temp < 0)
		temp = -temp;
	while (temp > 0)
	{
		str[i] = temp % 10 + 48;
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

static size_t	calculateallocate(int n)
{
	size_t	i;
	int		temp;

	i = 0;
	temp = n;
	if (temp < 0)
	{
		temp = -temp;
		i++;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (calculateallocate(n) + 1));
	if (!str)
		return (0);
	str = ia(n, str);
	str = strrev(str);
	return (str);
}
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%s\n", ft_itoa(atoi(argv[1])));
}*/
