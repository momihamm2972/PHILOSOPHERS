/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:13:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/28 20:20:08 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// destroyyyyyyyyyyyyyy

void	init_the_philos(t_philo **ph, int num_ph, char **vi, t_utils *tool);

void	mr(void)
{
	system ("leaks philo");
}

void	ft_usleep(long time)
{
	long	current;

	current = ft_now();
	while ((ft_now () - current) <= (time))
		usleep(100);
}

void	initial_utils(t_utils **my_struct, char **victor)
{
	(*my_struct)->number_of_philosophers = (int)ft_atoi(victor[1]);
	(*my_struct)->time_to_die = (int)ft_atoi(victor[2]);
	(*my_struct)->time_to_eat = (int)ft_atoi(victor[3]);
	(*my_struct)->time_to_sleep = (int)ft_atoi(victor[4]);
	(*my_struct)->number_must_eat = -1;
	if (victor[5])
		(*my_struct)->number_must_eat = (int )ft_atoi(victor[5]);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_philo			*last;
	t_utils			*utils;
	int				indx;

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
		initial_utils (&utils, av);
		init_the_philos (&philo, ft_atoi(av[1]), av, utils);
		// printf ("================\n");
		// printf ("================\n");
		// printf ("==========>>>>>%p\n",philo);
		// printf ("================\n");
		// while (philo)
		// {
		// 	printf ("police====>%d\n", philo->id);
		// 	philo = philo->next;
		// }
		destroy_forks (philo, ft_atoi (av[1]));
		pthread_mutex_destroy (&utils->print);
		pthread_mutex_destroy (&utils->mtx_last_arg);
		// pthread_mutex_destroy (utils->the_mutex_of_redone);
	}
}

void	init_the_philos(t_philo **ph, int num_ph, char **vi, t_utils *tool)
{
	pthread_mutex_t	redone;
	t_philo			*last;
	int				indx;

	indx = 1;
	while (indx <= num_ph)
	{
		ft_lstadd_back (ph, ft_lstnew (indx, vi, tool));
		indx++;
	}
	last = (*ph);
	pthread_mutex_init (&redone, NULL);
	// while (last)
	// {
		last->utils->the_mutex_of_redone = &redone;
	// 	last = last->next;
	// }
	last = ft_lstlast(ph);
	if (!last)
		return (free(ph), free(tool));
	last->next = (*ph);
	(*ph)->utils->begin_sumulation = ft_now();
	pthread_mutex_init (&(*ph)->utils->print, NULL);
	pthread_mutex_init (&(*ph)->utils->mtx_last_arg, NULL);
	create_threads (*ph, (*ph)->utils->begin_sumulation);
}

//errs
/*
./philo  4 610 200 2147483648 ==>> protect max int (rtn max long in ft_atoi)
destroy mutexes 
rah mdistroyitch wa7d lmutex;
*/