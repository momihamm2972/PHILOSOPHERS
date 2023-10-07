/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_use_agrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:55:14 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/07 18:40:22 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_arg (char *str)
{
	int indx;

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
	return (0);
}

int	ft_args (char *str)
{
	int check;
	
	check = check_arg (str);
	if (check == -1)
		return (-1);
	// if (indx == 1)
	// 	philo->number_of_philosophers = ft_atoi (str);
	// else if (indx == 2)
	// 	philo->time_to_die = ft_atoi (str);
	// else if (indx == 3)
	// 	philo->time_to_eat = ft_atoi (str);
	// else if (indx == 4)
	// 	philo->time_to_sleep = ft_atoi (str);
	// else if (indx == 5)
	// 	philo->number_of_times_each_philosopher_must_eat = ft_atoi (str);
	return (0);
}
