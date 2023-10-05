/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:02:09 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/05 11:28:24 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*********************************parssing*************************************/
typedef struct var_s
{
    char	*virgin;
	char	*ptr;
	char	**n_virgin;
	// int		num_of_ac;
}t_vars;
/******************************************************************************/
/**************************************philo***********************************/
typedef struct philo
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}t_philo;

/******************************************************************************/

// char	*ft_strjoin(char const *s1, char const *s2);
long long	ft_atoi(char *str);
int	ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *to, const void *from, size_t len);
// char	**ft_split(char *s, char c);
// int	num_of_word(char *s, char c);
// void	free_all(char **s, int ptrs);
// char	*ft_substr(char *s, int start, int len);
int check_arg (char *str);
int	ft_args (int indx, t_philo *philo, char *str);
int	ft_isalpha(int c);
int	ft_isdigit(int c);

#endif