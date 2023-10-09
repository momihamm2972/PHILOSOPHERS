# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 02:33:50 by momihamm          #+#    #+#              #
#    Updated: 2023/10/09 19:38:11 by momihamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Werror -Wextra -fsanitize=thread
FILES = philo.c\
		utils.c\
		utils1.c\
		utils2.c\
		linked_list.c\
		creat_threads.c\
		check_use_agrs.c

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