/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:00:07 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/27 22:47:06 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int content, char **victor, t_utils *utils0)
{
	t_philo	*head;

	(void) victor;
	head = malloc (sizeof (t_philo));
	if (!head)
		return (NULL);
	head->id = content;
	head->utils = (void *)utils0;
	head->done = false;
	head->num_of_eat_last = 0;
	head->utils->reach_goal = 0;
	head->next = NULL;
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
