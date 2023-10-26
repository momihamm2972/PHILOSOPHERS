/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:13:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/26 02:46:22 by momihamm         ###   ########.fr       */
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
	t_philo			*philo = NULL;
	t_philo			*last = NULL;
	pthread_mutex_t redone;
	// pthread_mutex_t modir;
	t_utils *utils = malloc (sizeof (t_utils));
	int				indx;
	
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
		while (indx <= ft_atoi(av[1]))
		{
			ft_lstadd_back (&philo, ft_lstnew (indx, av, utils));
			indx++;
		}
		last = philo;
		// pthread_mutex_init (&redone, NULL);
		// pthread_mutex_init (&modir, NULL);
		// last->utils->print = redone;
		// last->next->utils->print = modir;
		// indx = 1;
		// while (indx <= ft_atoi(av[1]))
		// {
		// 	// printf ("kmi\n");
		// 	printf (">>>>f>>>%p>>>>>\n", &last->utils);
		// 	last = last->next;
		// 	indx++;
		// }
		// exit (0);
		pthread_mutex_init (&redone, NULL);
		while (last)
		{
			last->utils->the_mutex_of_mikwad = &redone;
			// last->utils->print = 
			last = last->next;
		}
		last = ft_lstlast(&philo);
		if (!last)
			return (free(philo), 0); // free list kamla
		last->next = philo;
		philo->utils->begin_sumulation = ft_now();
		pthread_mutex_init (&philo->utils->print, NULL);
		create_threads (philo, philo->utils->begin_sumulation);
		return (0);
	}
}
