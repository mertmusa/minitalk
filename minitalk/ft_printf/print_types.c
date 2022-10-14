/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:24:27 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/28 03:37:10 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *str)
{
	int	i;
	int	printf_retval;

	i = 0;
	printf_retval = 0;
	if (!str)
		printf_retval += print_string("(null)");
	else
	{
		while (str[i])
		{
			printf_retval += putchar(str[i]);
			i++;
		}
	}
	return (printf_retval);
}

int	print_decimal(int c)
{
	char	*str;
	int		printf_retval;

	printf_retval = 0;
	str = ft_itoa(c);
	if (!str)
		return (printf_retval);
	printf_retval += print_string(str);
	free (str);
	return (printf_retval);
}

int	print_void(uintptr_t ptr)
{
	int		printf_retval;

	printf_retval = 0;
	printf_retval += print_string("0x");
	if (ptr == 0)
		printf_retval += putchar('0');
	else
		printf_retval += print_ptr(ptr);
	return (printf_retval);
}

int	print_unsigned(unsigned int c)
{
	char	*str;
	int		printf_retval;

	printf_retval = 0;
	str = ft_uitoa(c);
	if (!str)
		return (printf_retval);
	printf_retval += print_string(str);
	free (str);
	return (printf_retval);
}
