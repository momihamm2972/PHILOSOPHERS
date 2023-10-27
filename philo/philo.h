/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:02:09 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/28 00:40:17 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// # include <stdio.h>
# include <stdbool.h>
// # include <stdlib.h>
// # include <unistd.h>
# include <pthread.h>
// # include <sys/time.h>
# include <libc.h>

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
	bool			done;
	int				num_of_eat_last;
	int				id;
	int				time_of_the_last;
	long			cu_time;
	long			last_meal;
	struct philo	*next;
	struct utils	*utils;
}t_philo;
/******************************************************************************/
/******************************************************************************/
typedef struct utils
{
	pthread_mutex_t	print;
	pthread_mutex_t	mtx_last_arg;
	pthread_mutex_t	*the_mutex_of_redone;
	int				number_of_philosophers;
	int				reach_goal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_must_eat;
	int				indx;
	long			begin_sumulation;
	bool			fidler;
	int				lm3elm;
}t_utils;
/******************************************************************************/

t_philo		*ft_lstlast(t_philo **lst);
t_philo		*ft_elimini(t_philo **lst, int first);
t_philo		*ft_lstnew(int content, char **victor, t_utils *utils0);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
void		*actions(void *john_jack_russo);
void		*ft_memcpy(void *to, const void *from, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		create_threads(t_philo *ph, long start);
void		ft_usleep(long time);
void		ft_exit(t_philo *last);
void		ft_reach(t_philo *last);
void		init_the_philos(t_philo *ph, int num_ph, char **vi, t_utils *tool);
int			ft_strlen(char *str);
int			check_arg(char *str);
int			creat_mutexs(t_philo *ph);
int			ft_args(char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			safe_printing(t_philo *ptr, char *rotine);
char		*ft_strdup(char *s1);
long		ft_now(void);
long long	ft_atoi(char *str);

#endif