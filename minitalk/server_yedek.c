/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_yedek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:51:30 by mtemel            #+#    #+#             */
/*   Updated: 2022/08/30 15:42:42 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

//sig_atomic_t last_received_signal = 0;

static int signal_pid=-1;

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

/*void	get_pid(int sig, siginfo_t *info, void *context)
{
	printf("pid of client: %d\n", info->si_pid);
}*/

void handle_sigusr1(int sig)
{
	static int i;
	static unsigned int j;

	if (i == 0)
		i = 1;
	if (sig == SIGUSR2)
	{
		j = i + j;
		//usleep(100);
	}
	i = i * 2;
	//ft_printf("%d\n", j);
	if(i == 256)
	{
		write(1, &j, 1);
		//ft_printf("\nreceived PID: %d\n", signal_pid);
		i = 0;
		j = 0;
		//ft_printf("\nreceived PID: %d\n", signal_pid);
	}
}

/*void signal_catcher(int signo, siginfo_t *info, void *context)
{
    last_received_signal = info->si_signo;
}*/

int main()
{
	struct sigaction sa;
	ft_printf("PID: %d\n", getpid());
	ft_memset (&sa, 0, sizeof (sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &handle_sigusr1;
	//sa.sa_sigaction = &handle_sigusr1;
	//sa.sa_sigaction = get_pid;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	//ft_printf("PID of signal sender = %d\n", signal_pid);
	while (1)
		pause();
	//kill(signal_pid, SIGUSR2);

}

//struct sigaction sa;
//		sa.sa_flags = SA_RESTART;
//		sa.sa_handler = &handle_sigusr1;
//		sigaction(SIGUSR1, &sa, NULL);
