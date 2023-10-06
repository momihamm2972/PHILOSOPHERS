/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:00:07 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/06 18:35:36 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_node	*ft_lstnew(int content)
{
	t_node	*head;

	head = malloc (sizeof (t_node));
	head->data = content;
	head->next = NULL;
	return (head);
}

t_node	*ft_lstlast(t_node **lst)
{
	t_node	*ptr;

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

t_node	*ft_elimini(t_node **lst, int first)
{
	t_node	*ptr;

	if ((*lst)->data != first)
		return (NULL);
	if ((*lst)->next->data == first)
		return ((*lst));
	ptr = (*lst);
	while (ptr->next)
	{
		if (ptr->next->data == first)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

// int main()
// {
//     t_node *mimi = ft_lstnew (91);
//     mimi->next = ft_lstnew (78);
//     mimi->next->next = ft_lstnew (60);
//     mimi->next->next->next = ft_lstnew (47);
//     t_node *last = ft_lstlast (&mimi);
//     last->next = mimi;
//     printf ("%d", last->next->data);
//     last = ft_elimini (&mimi, 91);
//     printf ("\n%d\n", last->data);
// }