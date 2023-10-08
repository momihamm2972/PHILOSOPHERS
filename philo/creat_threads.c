/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:07:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/08 14:19:44 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*fun()
{
	// while (1);
		printf ("hahya kador bhat idrbolha lore  \n");
	return (NULL);
}

void	*actions(void *john_jack_russo)
{
	printf ("machkil>>>>%d<<<<\n",((t_philo *)john_jack_russo)->id);
	return (NULL);
}

int	creat_threads(t_philo *ph)
{
	t_philo	*ptr;
	int		indx;

	indx  = 0;
	if (!ph)
		return (-1);
	ptr = ph;
	while (indx < ph->number_of_philosophers)
	{
		// printf ("wiwi>>%d<<\n",indx);
		pthread_create (&ph->the_thread, NULL, &actions, ptr);
		// pthread_join (ph->the_thread, NULL);
		ptr = ptr->next;
		indx++;
	}
	return (0);
}