# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 11:53:28 by ynguyen           #+#    #+#              #
#    Updated: 2023/08/05 15:40:52 by ynguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	philo
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -pthread -g

SRC	=	free.c			\
		ft_printf.c		\
		init_data.c		\
		main.c			\
		routine.c		\
		thread_me.c		\
		time.c			\
		utils.c			

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:	
		rm -f *.o

fclean:	clean 
		rm -f philo

re: fclean all

.PHONY: all clean fclean re
