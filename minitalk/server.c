/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:51:30 by mtemel            #+#    #+#             */
/*   Updated: 2022/08/30 15:57:05 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *)b;
	while (i < len)
	{
		t[i] = (unsigned char)c;
		i++;
	}
	return ((void *)t);
}

void	handle_sigusr1(int sig)
{
	static int			i;
	static unsigned int	j;

	if (i == 0)
		i = 1;
	if (sig == SIGUSR2)
	{
		j = i + j;
	}
	i = i * 2;
	if (i == 256)
	{
		write(1, &j, 1);
		i = 0;
		j = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	ft_memset (&sa, 0, sizeof (sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
