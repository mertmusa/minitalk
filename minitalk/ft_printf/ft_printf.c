/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:11:37 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/28 04:45:45 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char c, va_list arg)
{
	int	printf_retval;

	printf_retval = 0;
	if (c == 'c')
		printf_retval += putchar(va_arg(arg, int));
	else if (c == 's')
		printf_retval += print_string(va_arg(arg, char *));
	else if (c == 'p')
		printf_retval += print_void(va_arg(arg, uintptr_t));
	else if (c == 'd' || c == 'i')
		printf_retval += print_decimal(va_arg(arg, int));
	else if (c == 'u')
		printf_retval += print_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		printf_retval += print_hexal(va_arg(arg, unsigned int), c);
	else
		printf_retval += putchar(c);
	return (printf_retval);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printf_retval;
	va_list	arg;

	printf_retval = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != 0)
			{
				printf_retval += ft_type(str[i + 1], arg);
				i++;
			}
		}
		else
			printf_retval += putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (printf_retval);
}
