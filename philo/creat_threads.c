/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:07:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/06 18:35:40 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*fun()
{
	while (1);
		// printf ("hahya kador bhat idrbolha lore  \n");
	return (NULL);
}

void	creat_threads(t_philo *ph)
{
	pthread_t	*num_of_threads;
	int indx = 0;

	num_of_threads = ft_calloc (ph->number_of_philosophers + 1, sizeof (pthread_t));
	printf ("<|%d|>\n",ph->number_of_philosophers);
	while (num_of_threads)
	{
		pthread_create (num_of_threads, NULL, &fun, NULL);
		puts ("kmi");
		pthread_detach (*num_of_threads);
		puts ("hak");
		indx++;
	printf ("\n-%d-\n",indx);
		num_of_threads++;
	}
	free (num_of_threads);
	
}