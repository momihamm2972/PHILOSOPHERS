/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:07:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/25 01:43:51 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*fun(void)
{
	printf ("hahya kador bhat idrbolha lore  \n");
	return (NULL);
}

long	ft_now(void)
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

int	safe_printing(t_philo *kmi, char *rotine)
{
	(void) rotine;
	pthread_mutex_lock (kmi->print);
	printf("%ld  %d %s\n", (ft_now () - kmi->cu_time) / 1000, kmi->id, rotine);
	pthread_mutex_unlock (kmi->print);
	return (0);
}

void	*actions(void *john_jack_russo)
{
	t_philo			*philo;

	philo = (t_philo *)john_jack_russo;
	philo->last_meal = ft_now();
	if (philo->id % 2 == 0)
	{
		ft_usleep(100);
		philo->last_meal += 100; 
	}
	while (1)
	{
		pthread_mutex_lock (&philo->the_mutex);
		safe_printing(philo, "has taken a fork");
		pthread_mutex_lock (&philo->next->the_mutex);
		safe_printing(philo, "has taken a fork");
		philo->last_meal = ft_now ();
		safe_printing(philo, "is eating");
		ft_usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock (&philo->the_mutex);
		pthread_mutex_unlock (&philo->next->the_mutex);
		safe_printing(philo, "is sleeping");
		ft_usleep (philo->time_to_sleep * 1000);
		safe_printing(philo, "is thinking");
	}
	return (NULL);
}

int	creat_mutexs(t_philo *ph)
{
	t_philo	*ptr;
	int		indx;

	if (!ph)
		return (-1);
	ptr = ph;
	indx = 0;
	while (indx < ph->number_of_philosophers)
	{
		pthread_mutex_init (&(ptr->the_mutex), NULL);
		ptr = ptr->next;
		indx++;
	}
	return (0);
}

int	create_threads(t_philo *ph, long start)
{
	t_philo	*ptr;
	int		indx;

	if (!ph)
		return (-1);
	ptr = ph;
	indx = 0;
	creat_mutexs(ph);
	while (indx < ph->number_of_philosophers)
	{
		ptr->cu_time = start;
		ptr->last_meal = ft_now ();
		pthread_create (&ptr->the_thread, NULL, &actions, ptr);
		ptr = ptr->next;
		indx++;
	}
	ptr = ph;
	indx = 0;
	while (indx < ph->number_of_philosophers)
	{
		pthread_detach(ptr->the_thread);
		ptr = ptr->next;
		indx++;
	}
	return (0);
}
