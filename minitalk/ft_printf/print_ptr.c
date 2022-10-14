/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:20:42 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/28 03:24:51 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calculate_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static char	*ptoa(uintptr_t ptr, char *str)
{
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	while (ptr != 0)
	{
		temp = ptr % 16;
		if (temp < 10)
			str[i] = temp + 48;
		else
			str[i] = temp + 87;
		ptr /= 16;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	print_ptr(uintptr_t ptr)
{
	int		printf_retval;
	char	*str;

	printf_retval = 0;
	str = (char *)malloc(sizeof(char) * (calculate_len(ptr) + 1));
	if (!str)
		return (0);
	str = ptoa(ptr, str);
	str = strrev(str);
	printf_retval += print_string(str);
	free (str);
	return (printf_retval);
}
