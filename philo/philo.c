/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:13:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/26 18:37:02 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mr(void)
{
	system ("leaks philo");
}

// make_list (t_philo *list, t_utils *my_utils, int num_philos, char *arg)
// {
// 	(void) num_philos;
// 	ft_lstadd_back (&list, ft_lstnew ())
// }

void	ft_usleep(long time)
{
	long	current;

	current = ft_now();
	while ((ft_now () - current) < (time))
		usleep(10);
}

int	main(int ac, char **av)
{
	pthread_mutex_t	redone;
	t_philo			*philo;
	t_philo			*last;
	t_utils			*utils;
	int				indx;
	// atexit (mr);
	philo = NULL;
	last = NULL;
	utils = malloc (sizeof (t_utils));
	if (ac == 5 || ac == 6)
	{
		indx = 1;
		while (indx < ac)
		{
			if (ft_args(av[indx]) == 0)
				indx++;
			else
				return (0);
		}
		utils->number_of_philosophers = ft_atoi (av[1]);
		utils->time_to_die = ft_atoi (av[2]);
		utils->time_to_eat = ft_atoi (av[3]);
		utils->time_to_sleep = ft_atoi (av[4]);
		utils->number_of_times_each_philosopher_must_eat = -1;
		if (av[5])
			utils->number_of_times_each_philosopher_must_eat = ft_atoi (av[5]);
		indx = 1;
		while (indx <= ft_atoi(av[1]))
		{
			ft_lstadd_back (&philo, ft_lstnew (indx, av, utils));
			indx++;
		}
		// while (++indx)
		// 	make_list (philo, utils, ft_atoi (av[1]), av[indx]);
		last = philo;
		pthread_mutex_init (&redone, NULL);
		while (last)
		{
			last->utils->the_mutex_of_mikwad = &redone;
			last = last->next;
		}
		last = ft_lstlast(&philo);
		if (!last)
			return (free(philo), 0); // free list kamla
		last->next = philo;
		philo->utils->begin_sumulation = ft_now();
		pthread_mutex_init (&philo->utils->print, NULL);
		create_threads (philo, philo->utils->begin_sumulation);
		// while (last)
		// {
		// 	printf ("_______________________________________________________________\n");
		// 	if (ft_now() - last->last_meal >= (long)1000)
		// 	{
		// 		printf ("lkmayaXXXXXXxxXXXXXXXXXXXXXXXXXxxxxXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		// 		exit (0);
		// 	}
		// 	last = last->next;
		// }
		return (0);
	}
}
