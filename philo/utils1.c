/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 06:50:46 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/06 18:35:14 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	indx;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	indx = 0;
	while (indx < (count * size))
		str[indx++] = 0;
	return (ptr);
}

void	*ft_memcpy(void *to, const void *from, size_t len)
{
	char	*to0;
	char	*from0;
	size_t	i;

	if (!to && !from)
		return (NULL);
	to0 = (char *)to;
	from0 = (char *)from;
	i = 0;
	while (i < len)
	{
		to0[i] = from0[i];
		i++;
	}
	return (to0);
}
// void	free_all(char **s, int ptrs)
// {
// 	int	indx;

// 	indx = 0;
// 	while (indx < ptrs)
// 	{
// 		free (s[indx]);
// 		indx++;
// 	}
// 	free(s);
// }

// int	num_of_word(char *s, char c)
// {
// 	int		indx;
// 	int		len;

// 	indx = 0;
// 	len = 0;
// 	if (s[indx] == '\0')
// 		return (0);
// 	while (s[indx])
// 	{
// 		if (s[indx] != c)
// 		{
// 			len++;
// 			while (s[indx] != c && s[indx])
// 				indx++;
// 			indx--;
// 		}
// 		indx++;
// 	}
// 	return (len);
// }

// char	**ft_split(char *s, char c)
// {
// 	char	**spl;
// 	int		r_s_e_c[4];

// 	if (!s)
// 		return (NULL);
// 	r_s_e_c[0] = -1;
// 	r_s_e_c[1] = 0;
// 	r_s_e_c[2] = 0;
// 	r_s_e_c[3] = num_of_word((char *)s, c);
// 	spl = (char **) ft_calloc ((r_s_e_c[3] + 1), sizeof(char *));
// 	if (!spl)
// 		return (NULL);
// 	while (++r_s_e_c[0] < r_s_e_c[3])
// 	{
// 		while (s[r_s_e_c[2]] && s[r_s_e_c[2]] == c)
// 			r_s_e_c[2]++;
// 		r_s_e_c[1] = r_s_e_c[2];
// 		while (s[r_s_e_c[2]] && s[r_s_e_c[2]] != c)
// 			r_s_e_c[2]++;
// 		spl[r_s_e_c[0]] = ft_substr(s, r_s_e_c[1], (r_s_e_c[2] - r_s_e_c[1]));
// 		if (!spl[r_s_e_c[0]])
// 			return (free_all(spl, r_s_e_c[3]), NULL);
// 		r_s_e_c[1] = r_s_e_c[2];
// 	}
// 	return (spl);
// }
