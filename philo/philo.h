/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:02:09 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/22 02:24:26 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/**********************************linked list*********************************/
typedef struct node
{
	int				data;
	struct node		*next;
}t_node;
/******************************************************************************/
/**************************************philo***********************************/
typedef struct philo
{
	pthread_t		the_thread;
	pthread_mutex_t	the_mutex;
	pthread_mutex_t *print;
	int				id;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				time_of_the_last;
	struct philo	*next;
}t_philo;
/******************************************************************************/

t_philo		*ft_lstlast(t_philo **lst);
t_philo		*ft_elimini(t_philo **lst, int first);
t_philo		*ft_lstnew(int content, char **victor);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
void		*actions(void *john_jack_russo);
void		*fun(void);
void		*ft_memcpy(void *to, const void *from, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(char *s1);
int			ft_strlen(char *str);
int			creat_threads(t_philo *ph);
int			check_arg(char *str);
int			creat_mutexs(t_philo *ph);
int			ft_args(char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int	safe_printing(t_philo *kmi, char *rotine);
long long	ft_atoi(char *str);

#endif