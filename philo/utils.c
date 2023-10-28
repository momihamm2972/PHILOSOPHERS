/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 06:28:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/28 03:59:56 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(char *str)
{
	long long	i_r_s[3];

	i_r_s[0] = -1;
	i_r_s[1] = 0;
	i_r_s[2] = 1;
	while (str[++i_r_s[0]] != '\0')
	{
		while (str[i_r_s[0]] == 32
			|| (str[i_r_s[0]] >= 9 && str[i_r_s[0]] <= 13))
			i_r_s[0]++;
		if (str[i_r_s[0]] == '-' || str[i_r_s[0]] == '+' )
		{
			if (str[i_r_s[0]] == '-' )
				i_r_s[2] = -1;
			i_r_s[0]++;
		}
		if (!(str[i_r_s[0]] >= '0' && str[i_r_s[0]] <= '9'))
			return (0);
		i_r_s[1] = (i_r_s[1] * 10) + str[i_r_s[0]] - '0';
	}
	return (i_r_s[1] * i_r_s[2]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len);
	return (str);
}
