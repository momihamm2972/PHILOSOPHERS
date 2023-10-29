/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:07:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/29 03:26:47 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	safe_printing(t_philo *ptr, char *rotine)
{
	pthread_mutex_lock (&ptr->utils->print);
	printf("%ld  %d %s\n", (ft_now () - ptr->cu_time), ptr->id, rotine);
	pthread_mutex_unlock (&ptr->utils->print);
	return (0);
}

void	the_five(t_philo *philo)
{
	if (philo->utils->number_must_eat != -1)
	{
		pthread_mutex_lock(&philo->utils->mtx_last_arg);
		philo->num_of_eat_last++;
		pthread_mutex_unlock(&philo->utils->mtx_last_arg);
	}
}

void	*actions(void *john_jack_russo)
{
	t_philo			*philo;

	philo = (t_philo *)john_jack_russo;
	if (philo->id % 2 == 0)
		ft_usleep(philo->utils->time_to_eat);
	while (1)
	{
		pthread_mutex_lock (&philo->the_mutex);
		safe_printing(philo, "has taken a fork");
		pthread_mutex_lock (&philo->next->the_mutex);
		safe_printing(philo, "has taken a fork");
		safe_printing(philo, "is eating");
		pthread_mutex_lock (&philo->utils->the_mutex_of_redone);
		philo->last_meal = ft_now ();
		pthread_mutex_unlock (&philo->utils->the_mutex_of_redone);
		ft_usleep(philo->utils->time_to_eat);
		pthread_mutex_unlock (&philo->the_mutex);
		pthread_mutex_unlock (&philo->next->the_mutex);
		the_five (philo);
		safe_printing(philo, "is sleeping");
		ft_usleep (philo->utils->time_to_sleep);
		safe_printing(philo, "is thinking");
	}
}

int	creat_mutexs(t_philo *ph)
{
	t_philo	*ptr;
	int		indx;

	if (!ph)
		return (-1);
	ptr = ph;
	indx = 0;
	while (indx < ph->utils->number_of_philosophers)
	{
		pthread_mutex_init (&(ptr->the_mutex), NULL);
		ptr = ptr->next;
		indx++;
	}
	return (0);
}

void	create_threads(t_philo *ph)
{
	t_philo	*ptr;
	t_philo	*last;
	int		indx;

	if (!ph)
		return ;
	ptr = ph;
	indx = 0;
	creat_mutexs(ph);
	while (indx < ph->utils->number_of_philosophers)
	{
		ptr->cu_time = ph->utils->begin_sumulation;
		ptr->last_meal = ft_now ();
		pthread_create (&ptr->the_thread, NULL, &actions, ptr);
		pthread_detach(ptr->the_thread);
		ptr = ptr->next;
		indx++;
	}
	last = ph;
	ft_reach (last);
}

// void	ft_reach(t_philo *last)
// {
// 	while (last)
// 	{
// 		pthread_mutex_lock (&last->utils->the_mutex_of_redone);
// 		if (ft_now() - last->last_meal >= (long)(last->utils->time_to_die))
// 		{
// 			ft_exit(last);
// 			break ;
// 		}
// 		pthread_mutex_lock(&last->utils->mtx_last_arg);
// 		if (last->utils->number_must_eat != -1 && last->done == false
// 			&& last->num_of_eat_last >= last->utils->number_must_eat)
// 		{
// 			last->done = true;
// 			last->utils->reach_goal++;
// 			if (last->utils->reach_goal == last->utils->number_of_philosophers)
// 			{
// 				pthread_mutex_lock(&last->utils->print);
// 				break ;
// 			}
// 		}
// 		pthread_mutex_unlock(&last->utils->mtx_last_arg);
// 		pthread_mutex_unlock (&last->utils->the_mutex_of_redone);
// 		last = last->next;
// 		usleep (100);
// 	}
// }
