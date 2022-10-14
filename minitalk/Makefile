# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 16:06:25 by mtemel            #+#    #+#              #
#    Updated: 2022/08/30 16:25:25 by mtemel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cd ft_printf && make all
	gcc -Wall -Wextra -Werror ft_printf/libftprintf.a server.c -o server
	gcc -Wall -Wextra -Werror ft_printf/libftprintf.a client.c -o client
clean:
	cd ft_printf && make clean
	rm -rf server client
fclean: clean
	cd ft_printf && make fclean
re: clean fclean all
