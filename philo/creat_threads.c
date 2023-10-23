/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:07:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/23 05:49:21 by momihamm         ###   ########.fr       */
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
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

int	safe_printing(t_philo *kmi, char *rotine)
{
	(void) rotine;
	pthread_mutex_lock (kmi->print);
	printf ("%ld  %d %s\n", (ft_time_of_living () - kmi->current_time) / 1000, kmi->id, rotine);
	pthread_mutex_unlock (kmi->print);
	return (0);
}



void	*actions(void *john_jack_russo)
{
	t_philo			*philo;
	// int				even;
	// int				timer;
	// long				time_of_the_last_meal;
	philo = (t_philo *)john_jack_russo;
	philo->last_meal = ft_time_of_living();
	// philo->timer = 0;
	// time_of_the_last_meal = ft_time_of_living();
	// printf (">>>>>>>>>>%ld\n", time_of_the_last_meal);
	if (philo->id % 2 == 0)
		usleep(100);
	// even = philo->time_to_die * 2;
	
	while (1)
	{
		// if ((ft_time_of_living() - time_of_the_last_meal) > (long)(philo->time_to_die * 1000))
		// {
		// 	safe_printing (philo, "is die 💀");
		// 	return (NULL);
		// }
		// printf ("<<<<<<<<<<<<<%ld\n", ft_time_of_living());
		// sleep(3);
		pthread_mutex_lock (&philo->the_mutex);
		safe_printing(philo, "has taken a fork");
		// printf ("kmi\n");
		pthread_mutex_lock (&philo->next->the_mutex);
		// printf ("113795\n");
		safe_printing(philo, "has taken a fork");
		// philo->timer += philo->time_to_eat;
		philo->last_meal = ft_time_of_living ();
		safe_printing(philo, "is eating");
		ft_usleep(philo->time_to_eat * 1000);
		// philo->last_meal = ft_time_of_living ();
		pthread_mutex_unlock (&philo->the_mutex);
		pthread_mutex_unlock (&philo->next->the_mutex);
		// philo->timer += philo->time_to_sleep;
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
	ph->timer = 0;
	creat_mutexs(ph);
	while (indx < ph->number_of_philosophers)
	{
		pthread_create (&ptr->the_thread, NULL, &actions, ptr);
		ptr->current_time = start;
		ph->last_meal = ft_time_of_living ();
		ptr = ptr->next;
		indx++;
	}
	ptr = ph;
	indx = 0;
	while (indx < ph->number_of_philosophers)
	{
		// pthread_join (ptr->the_thread, NULL);
		pthread_detach(ptr->the_thread);
		ptr = ptr->next;
		indx++;
	}
	return (0);
}
