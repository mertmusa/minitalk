/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_yedek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:51:30 by mtemel            #+#    #+#             */
/*   Updated: 2022/08/30 15:41:40 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			pos;
	char		*s;

	pos = 1;
	i = 0;
	res = 0;
	s = (char *)str;
	while (s[i] == ' ' || (s[i] > 8 && s[i] < 14))
		i++;
	if (s[i] == '+' || s[i] == '-')
		pos = 1 - 2 * (s[i++] == '-');
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 +(s[i++] - 48);
		if (res > 2147483647 && pos == 1)
			return (-1);
		else if (res > 2147483648 && pos == -1)
			return (0);
	}
	return ((int)(res * pos));
}

void	send_func(int pid, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while(j < 8)
		{
			if(s[i] & 1)
			{
				kill(pid, SIGUSR2);
				usleep(10);
			}
			else
			{
				kill(pid, SIGUSR1);
				usleep(10);
			}
			s[i] = s[i] >> 1;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t pid;

	pid = ft_atoi(argv[1]);
	if(argc == 3)
	{
		send_func(pid, argv[2]);
		//ft_printf("client (my process) Pid: %d", getpid());
	}
}

//		struct sigaction sa;
//		sa.sa_flags = SA_RESTART;
//		sa.sa_handler = &handle_sigusr1;
//		sigaction(SIGUSR1, &sa, NULL);
