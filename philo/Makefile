# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momihamm <momihamm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 02:33:50 by momihamm          #+#    #+#              #
#    Updated: 2023/09/19 03:33:51 by momihamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Werror -Wextra -fsanitize=address
FILES = excution0.c\
		excution1.c\
		excution2.c\
		excution3.c\
		excution4.c\
		excution5.c\
		excution6.c\
		parssing0.c\
		parssing1.c\
		parssing2.c\
		parssing3.c\
		parssing4.c\
		parssing5.c\
		parssing6.c\
		philo.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

%.o : %.c philo.h
		$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
	$(CC) $(FILES) $(FLAGS) -o $(NAME)

clean :
		@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)

re : fclean all 