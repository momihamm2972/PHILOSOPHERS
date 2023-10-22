/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:07:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/22 02:36:44 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*fun(void)
{
	printf ("hahya kador bhat idrbolha lore  \n");
	return (NULL);
}

long	ft_time_of_living(void)
{
	struct timeval	time;

	gettimeofday (&time, NULL);
	return ((time.tv_sec * 1000000000) + time.tv_usec);
}

int	safe_printing(t_philo *kmi, char *rotine)
{
	(void) rotine;
	pthread_mutex_lock (kmi->print);
	printf ("philo_num %d %s\n", kmi->id, rotine);
	pthread_mutex_unlock (kmi->print);
	return (0);
}

void	*actions(void *john_jack_russo)
{
	t_philo			*philo;
	// struct timeval /	time;
	int				even;
	long				time_of_the_last_meal;

	philo = (t_philo *)john_jack_russo;
	time_of_the_last_meal = ft_time_of_living();
	// gettimeofday (&time, NULL);
	// printf ("lkmaya == %ld\n", time_of_the_last_meal);
	if (philo->id % 2 == 0)
		usleep(100);
	even = philo->time_to_die * 2;
	while (1)
	{
		pthread_mutex_lock (&philo->the_mutex);
		safe_printing(philo, "has one fork 🍴");
		// printf ("philo_num %d has taken his first fork 🍴\n", philo->id);
		pthread_mutex_lock (&philo->next->the_mutex);
		safe_printing(philo, "has two fork 🍴");
		// printf ("philo_num %d has taken his second fork 🍴\n", philo->id);
		// printf ("philo_num %d is eating 🧅\n", philo->id);
		safe_printing(philo, "is eating 🧅");
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock (&philo->the_mutex);
		pthread_mutex_unlock (&philo->next->the_mutex);
		// printf ("philo_num %d is sleeping 💤\n", philo->id);
		safe_printing(philo, "is sleeping 💤");
		usleep (philo->time_to_sleep * 1000);
		// printf ("philo_num %d is thinking 🧠\n", philo->id);
		safe_printing(philo, "is thinking 🧠");
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

int	creat_threads(t_philo *ph)
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
		pthread_create (&ptr->the_thread, NULL, &actions, ptr);
		ptr = ptr->next;
		indx++;
	}
	ptr = ph;
	indx = 0;
	while (indx < ph->number_of_philosophers)
	{
		pthread_join (ptr->the_thread, NULL);
		ptr = ptr->next;
		indx++;
	}
	return (0);
}
