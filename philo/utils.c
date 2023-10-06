/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 06:28:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/06 18:35:10 by momihamm         ###   ########.fr       */
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
		if ((i_r_s[1] * i_r_s[2]) > 2147483647)
			return (0);
		if ((i_r_s[1] * i_r_s[2]) < -2147483648)
			return (0);
	}
	return (i_r_s[1] * i_r_s[2]);
}
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str1;
// 	char	*str2;
// 	char	*buff;
// 	int		indx_of_conca;
// 	int		indx;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	str1 = (char *)s1;
// 	str2 = (char *)s2;
// 	indx_of_conca = 0;
// 	buff = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
// 	if (!buff)
// 		return (NULL);
// 	indx = 0;
// 	while (s1[indx] != '\0')
// 	{
// 		buff[indx] = str1[indx];
// 		indx++;
// 	}
// 	while (indx < (ft_strlen(str1) + ft_strlen(str2)))
// 		buff[indx++] = str2[indx_of_conca++];
// 	buff[indx] = '\0';
// 	return (buff);
// }

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
// char	*ft_substr(char *s, int start, int len)
// {
// 	char	*alloc_adds;
// 	int		str_len;
// 	int		indx;
// 	int		end;

// 	if (!s)
// 		return (NULL);
// 	str_len = ft_strlen (s);
// 	if (start >= str_len)
// 		return (ft_calloc (1, sizeof(char)));
// 	if (len > ft_strlen(&s[start]))
// 		len = ft_strlen(&s[start]);
// 	alloc_adds = (char *) ft_calloc(len + 1, sizeof (char));
// 	if (!alloc_adds)
// 		return (NULL);
// 	indx = 0;
// 	end = start + len;
// 	while (start < end && indx < len + 1 && s[start])
// 		alloc_adds[indx++] = s[start++];
// 	return (alloc_adds);
// }
