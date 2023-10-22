/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:13:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/22 05:44:03 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mr(void)
{
	system ("leaks philo");
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	t_philo		*last;
	pthread_mutex_t safe;
	int			indx;
	long		last_meal;
	// atexit (mr);
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
			ft_lstadd_back (&philo, ft_lstnew (indx, av));
			indx++;
		}
		last = ft_lstlast (&philo);
		if (!last)
			return (0);
		last->next = philo;
		indx = 1;
		last = philo;
		while (indx <= ft_atoi(av[1]))
		{
			last->print = &safe;
			last = last->next;
			indx++;
		}
		creat_threads (philo);
		last_meal = ft_time_of_living();
		while (1)
		{
			if ((ft_time_of_living() - last_meal) > (long)(philo->time_to_die * 1000))
			{
				safe_printing (philo, "is die 💀");
				return (0);
			}
		}
		
		free (philo);
	}
}
