/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_use_agrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:55:14 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/28 02:56:11 by momihamm         ###   ########.fr       */
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
	if (ft_atoi (str) < 0 || ft_atoi (str) > 2147483647)
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
