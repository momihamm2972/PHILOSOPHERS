/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:02:09 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/09 19:22:55 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

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
	int				id;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	struct philo	*next;
}t_philo;
/******************************************************************************/

// char	*ft_strjoin(char const *s1, char const *s2);
t_philo	*ft_lstlast(t_philo **lst);
t_philo	*ft_elimini(t_philo **lst, int first);
t_philo	*ft_lstnew(int content, char **victor);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
int	creat_threads(t_philo *ph);
void	*actions(void *john_jack_russo);
void	*fun();
long long	ft_atoi(char *str);
int	ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *to, const void *from, size_t len);
// char	**ft_split(char *s, char c);
// int	num_of_word(char *s, char c);
// void	free_all(char **s, int ptrs);
// char	*ft_substr(char *s, int start, int len);
int check_arg (char *str);
int	creat_mutexs(t_philo *ph);
int	ft_args (char *str);
int	ft_isalpha(int c);
int	ft_isdigit(int c);

#endif