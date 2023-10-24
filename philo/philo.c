/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:13:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/24 02:08:19 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mr(void)
{
	system ("leaks philo");
}
void    ft_usleep(long time)
{
    long    current;

    current = ft_time_of_living();
    while((ft_time_of_living() -  current) < (time))
    {
        usleep(10);
    }
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	t_philo		*last;
	pthread_mutex_t safe;
	int			indx;
	long			begin_sumulation;
	// long		last_meal;
	// atexit (mr);
	if (ac == 5 || ac == 6)
	{
		pthread_mutex_init (&safe, NULL);
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
		// last = ft_lstlast (&philo);
		// if (!last)
		// 	return (free(philo), 1); // free list kamla
		// last->next = philo;
		// indx = 1;
		// last = philo;
		// while (indx <= ft_atoi(av[1]))
		// {
		// 	last->print = &safe;
		// 	last = last->next;
		// 	indx++;
		// }
		last = philo;
		while (last)
		{
			last->print = &safe;
			last = last->next;
		}
		last = ft_lstlast(&philo);
		if (!last)
			return (free(philo), 1); // free list kamla
		last->next = philo;
		begin_sumulation = ft_time_of_living();
		create_threads (philo, begin_sumulation);
		// last_meal = ft_time_of_living();
		last = philo;
		while (1)
		{
			
			if (ft_time_of_living() - last->last_meal >= (long)(last->time_to_die * 1000))
			{
				safe_printing (last, "died💀💀💀💀💀💀💀💀💀💀💀💀💀💀");
				// printf ("die\n");
				
				return (0);
			}
			// last = last->next;
		}
		free (philo);
	}
}
