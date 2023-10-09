/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:07:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/09 19:35:28 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*fun()
{
	// while (1);
		printf ("hahya kador bhat idrbolha lore  \n");
	return (NULL);
}

void	*actions(void *john_jack_russo)
{
	t_philo	*philo;

	philo = (t_philo *)john_jack_russo;

	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock (&philo->the_mutex);
		printf ("philo: %d has taken a fork\n", philo->id);
		pthread_mutex_lock (&philo->next->the_mutex);
		printf ("philo: %d has taken a fork\n", philo->id);
		printf ("philo: %d is eating\n", philo->id);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock (&philo->the_mutex);
		pthread_mutex_unlock (&philo->next->the_mutex);
		printf ("philo: %d is sleeping\n", philo->id);
		usleep(philo->time_to_sleep * 1000);
		printf ("philo: %d is thinking\n", philo->id);
	}
	return (NULL);
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
		// printf ("wiwi>>%d<<\n",indx);
		pthread_create (&ptr->the_thread, NULL, &actions, ptr);
		// pthread_join (ptr->the_thread, NULL);
		ptr = ptr->next;
		indx++;
	}
	return (0);
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
		pthread_mutex_init (&( ptr->the_mutex), NULL);
		ptr = ptr->next;
		indx++;
	}
	return (0);
}
