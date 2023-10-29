/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_use_agrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:55:14 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/29 03:27:05 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char *str)
{
	int	indx;

	if (ft_strlen (str) == 0)
		return (-1);
	indx = 0;
	while (str[indx])
	{
		if (str[indx] == '+')
			indx++;
		if (ft_isdigit (str[indx]) == 0)
			return (-1);
		indx++;
	}
	if (ft_atoi (str) <= 0 || ft_atoi (str) > 2147483647)
		return (-1);
	return (0);
}

int	ft_args(char *str)
{
	int	check;

	check = check_arg (str);
	if (check == -1)
	{
		printf ("args not suported!!\n");
		return (-1);
	}
	return (0);
}

void	ft_reach(t_philo *last)
{
	while (last)
	{
		pthread_mutex_lock (&last->utils->the_mutex_of_redone);
		if (ft_now() - last->last_meal >= (long)(last->utils->time_to_die))
		{
			ft_exit(last);
			break ;
		}
		pthread_mutex_lock(&last->utils->mtx_last_arg);
		if (last->utils->number_must_eat != -1 && last->done == false
			&& last->num_of_eat_last >= last->utils->number_must_eat)
		{
			last->done = true;
			last->utils->reach_goal++;
			if (last->utils->reach_goal == last->utils->number_of_philosophers)
			{
				pthread_mutex_lock(&last->utils->print);
				break ;
			}
		}
		pthread_mutex_unlock(&last->utils->mtx_last_arg);
		pthread_mutex_unlock (&last->utils->the_mutex_of_redone);
		last = last->next;
		usleep (100);
	}
}
