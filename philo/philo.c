/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:13:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/26 23:32:55 by momihamm         ###   ########.fr       */
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

void	initial_utils (t_utils **my_struct, char **victor)
{
	
	(*my_struct)->number_of_philosophers =  (int )ft_atoi(victor[1]);
	(*my_struct)->time_to_die =  (int )ft_atoi(victor[2]);
	(*my_struct)->time_to_eat =  (int )ft_atoi(victor[3]);
	(*my_struct)->time_to_sleep =  (int )ft_atoi(victor[4]);
	(*my_struct)->number_of_times_each_philosopher_must_eat = -1;
	if(victor[5])
		(*my_struct)->number_of_times_each_philosopher_must_eat = (int )ft_atoi(victor[5]);
	// if (order == 1)
	// 	my_struct->number_of_philosophers = ft_atoi (victor);
	// else if (order == 2)
	// 	my_struct->time_to_die = ft_atoi (victor);
	// else if (order == 3)
	// 	my_struct->time_to_eat = ft_atoi (victor);
	// else if (order == 4)
	// 	my_struct->time_to_sleep = ft_atoi (victor);
	// else if (order == 5)
	// 	my_struct->number_of_times_each_philosopher_must_eat = ft_atoi (victor);
}

int	main(int ac, char **av)
{
	pthread_mutex_t	redone;
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
		indx = 1;
		initial_utils (&utils, av);
		// printf("-------------->>%d<<-----------\n", utils->number_of_times_each_philosopher_must_eat);
		// while (indx++ <= ft_atoi (av[1]) && av[indx])
		// {
		// 	printf ("indx== %d\n",indx);
		// 	// indx++;
		// }
		indx = 1;
		while (indx <= ft_atoi(av[1]))
		{
			ft_lstadd_back (&philo, ft_lstnew (indx, av, utils));
			indx++;
		}
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
		pthread_mutex_init (&philo->utils->mtx_last_arg, NULL);		
		create_threads (philo, philo->utils->begin_sumulation);
		return (0);
	}
}
