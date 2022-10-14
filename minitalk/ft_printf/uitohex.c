/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitohex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:16:38 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/28 03:37:18 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_len(unsigned int uc)
{
	int	len;

	len = 0;
	while (uc != 0)
	{
		uc /= 16;
		len++;
	}
	return (len);
}

static char	*uitoa(unsigned int uc, char *str, char c)
{
	unsigned int	temp;
	unsigned int	i;

	i = 0;
	temp = 0;
	while (uc != 0)
	{
		temp = uc % 16;
		if (temp < 10)
			str[i] = temp + 48;
		else
		{
			if (c == 'x')
				str[i] = temp + 87;
			else if (c == 'X')
				str[i] = temp + 55;
		}
		uc /= 16;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	uitohex(unsigned int uc, char c)
{
	int		printf_retval;
	char	*str;

	printf_retval = 0;
	str = (char *)malloc(sizeof(char) * (calculate_len(uc) + 1));
	if (!str)
		return (0);
	str = uitoa(uc, str, c);
	str = strrev(str);
	printf_retval += print_string(str);
	free (str);
	return (printf_retval);
}

int	print_hexal(unsigned int uc, char c)
{
	int		printf_retval;

	printf_retval = 0;
	if (uc == 0)
		printf_retval += putchar('0');
	else
		printf_retval += uitohex(uc, c);
	return (printf_retval);
}
