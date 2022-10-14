/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:51:30 by mtemel            #+#    #+#             */
/*   Updated: 2022/08/05 11:57:51 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf scanf
#include <stdlib.h> //wait
#include <signal.h>
#include <unistd.h>

void	handle_sigusr1(int sig)
{
	printf("multiplication is repetitive addition!\n");
}

int	main(int argc, char **argv)
{
	int	pid = fork();
	if(pid == -1)
	{
		return 1;
	}

	//printf("%d\n", getpid());
	//printf("%d\n", pid);

	if(pid == 0)
	{//child process
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else
	{//parent process
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);

		int x;
		printf("What is the result of 3*5: ");
		scanf("%d", &x);
		if (x == 15)
		{
			printf("Right!\n");
		}
		else
		{
			printf("Wrong!\n");
		}
		wait(NULL);
	}
}

//struct sigaction sa;
//		sa.sa_flags = SA_RESTART;
//		sa.sa_handler = &handle_sigusr1;
//		sigaction(SIGUSR1, &sa, NULL);
