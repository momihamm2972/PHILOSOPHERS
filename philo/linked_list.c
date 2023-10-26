/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:00:07 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/26 02:41:05 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int content, char **victor, t_utils *utils0)
{
	t_philo	*head;

	head = malloc (sizeof (t_philo));
	if (!head)
		return (NULL);
	head->number_of_philosophers = ft_atoi (victor[1]);
	head->time_to_die = ft_atoi (victor[2]);
	head->time_to_eat = ft_atoi (victor[3]);
	head->time_to_sleep = ft_atoi (victor[4]);
	head->id = content;
	head->utils = (void	*)utils0;
	head->number_of_times_each_philosopher_must_eat = -1;
	head->next = NULL;
	head->utils->lm3elm = head->time_to_die;
	if (victor[5])
		head->number_of_times_each_philosopher_must_eat = ft_atoi (victor[5]);
	return (head);
}

t_philo	*ft_lstlast(t_philo **lst)
{
	t_philo	*ptr;

	if (!(*lst))
		return (NULL);
	if ((*lst)->next == NULL)
		return ((*lst));
	ptr = (*lst);
	while (ptr->next)
	{
		if (ptr->next->next == NULL)
			return (ptr->next);
		ptr = ptr->next;
	}
	return (NULL);
}

t_philo	*ft_elimini(t_philo **lst, int first)
{
	t_philo	*ptr;

	if ((*lst)->id != first)
		return (NULL);
	if ((*lst)->next->id == first)
		return ((*lst));
	ptr = (*lst);
	while (ptr->next)
	{
		if (ptr->next->id == first)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*the_last;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	the_last = ft_lstlast(lst);
	the_last->next = new;
}
