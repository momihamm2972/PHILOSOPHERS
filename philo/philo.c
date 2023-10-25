/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:13:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/25 04:11:04 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mr(void)
{
	system ("leaks philo");
}

void	ft_usleep(long time)
{
	long	current;

	current = ft_now();
	while ((ft_now () -  current) < (time))
		usleep(10);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_philo			*last;
	pthread_mutex_t safe;
	pthread_mutex_t redone;
	int				indx;
	long			begin_sumulation;
	bool 			fidler;

	fidler = true;
	if (ac == 5 || ac == 6)
	{
		pthread_mutex_init (&safe, NULL);
		// pthread_mutex_init (&s, NULL);
		indx = 1;
		while (indx < ac)
		{
			if (ft_args(av[indx]) == 0)
				indx++;
			else
				return (0);
		}
		indx = 1;
		while (indx <= ft_atoi(av[1]))
		{
			ft_lstadd_back (&philo, ft_lstnew (indx, av));
			indx++;
		}
		last = philo;
		pthread_mutex_init (&redone, NULL);
		while (last)
		{
			last->print = &safe;
			last->the_mutex_of_mikwad = &redone;
			last = last->next;
		}
		last = ft_lstlast(&philo);
		if (!last)
			return (free(philo), 1); // free list kamla
		last->next = philo;
		begin_sumulation = ft_now();
		create_threads (philo, begin_sumulation);
		last = philo;
		while (fidler)
		{
			
			pthread_mutex_lock (last->the_mutex_of_mikwad);
			// pthread_mutex_lock (last->print);
			if (ft_now() - last->last_meal >= (long)(/*last->time_to_die **/ 1000))
			{
				// pthread_mutex_unlock (last->print);
				pthread_mutex_unlock (last->the_mutex_of_mikwad);
				safe_printing (last, "died💀💀💀💀💀💀💀💀💀💀💀💀💀💀");
				fidler = false;
				return (0);
			}
			// pthread_mutex_unlock (last->print);
			pthread_mutex_unlock (last->the_mutex_of_mikwad);
			last = last->next;
		}
		free (philo);
	}
}
