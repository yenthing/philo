NAME =	philo

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -g -pthread

SRC	=	philo.c	\
		init_data.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:	
		rm -f *.o

fclean:	clean 
		rm -f philo

re: fclean all

.PHONY: all clean fclean re