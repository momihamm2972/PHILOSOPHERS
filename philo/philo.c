/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:13:22 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/08 14:20:57 by momihamm         ###   ########.fr       */
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
	// atexit (mr);
	if (ac == 5 || ac == 6)
	{
		// printf ("dkhelt\n");
		indx = 1;		
		while (indx < ac)
		{
			if (ft_args(av[indx]) == 0)
				indx++;
			else
				return (0);
		}
		indx = 1;
		// printf ("kmi\n");
		while (indx <= ft_atoi(av[1]))
		{
			ft_lstadd_back (&philo, ft_lstnew (indx, av));
			indx++;
		}
		// printf ("tkma\n");
		t_philo *last = ft_lstlast (&philo);
		if (!last)
			return (0);
		last->next = philo;
		// printf ("us\n");
		// while (philo)
		// {
		// 	printf ("%d\n",philo->id);
		// 	philo = philo->next;
		// }
		// printf ("number_of_philosophers  %d\n",philo->number_of_philosophers);
		creat_threads (philo);
		while (1);
		// printf ("skip\n");
		free (philo);
	}
}
