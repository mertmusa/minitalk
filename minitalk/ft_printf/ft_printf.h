/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:18:00 by mtemel            #+#    #+#             */
/*   Updated: 2022/04/28 10:11:49 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_type(char c, va_list arg);
int		putchar(int c);
int		print_string(char *str);
int		print_void(uintptr_t ptr);
int		print_decimal(int c);
int		print_unsigned(unsigned int c);
int		print_hexal(unsigned int uc, char c);

char	*ft_itoa(int n);
int		print_ptr(uintptr_t ptr);
char	*ft_uitoa(unsigned int n);
int		uitohex(unsigned int uc, char c);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*strrev(char *c);

#endif
