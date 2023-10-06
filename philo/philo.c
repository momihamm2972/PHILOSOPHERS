/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:13:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/06 12:35:21 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mr(void)
{
	system ("leaks philo");
}

int main(int ac, char **av)
{
	t_philo	*philo;
	int indx;
	atexit (mr);
	if (ac == 5 || ac == 6)
	{
		philo = malloc (sizeof (t_philo));
		philo->number_of_times_each_philosopher_must_eat = -1;
		indx = 1;		
		while (indx < ac)
		{
			if (ft_args(indx, philo, av[indx]) == 0)
				indx++;
			else
			{
				free (philo);
				return (0);
			}
		}
		printf ("number_of_philosophers  %d\n",philo->number_of_philosophers);
		printf ("time_to_die  %d\n",philo->time_to_die);
		printf ("time_to_eat  %d\n",philo->time_to_eat);
		printf ("time_to_sleep  %d\n",philo->time_to_sleep);
		printf ("number_of_times_each_philosopher_must_eat  %d\n",philo->number_of_times_each_philosopher_must_eat);
		creat_threads(philo);
		free (philo);
	}
}
