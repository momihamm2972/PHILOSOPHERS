/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:42:16 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/26 02:36:42 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_exit(t_philo *last)
{
	// pthread_mutex_lock (&last->utils->print);
	printf("%ld  %d %s\n", (ft_now () - last->cu_time), last->id, "died lah irhmoXXXXX   XXXX    XXXXXXXXXXXXXXX");
}

