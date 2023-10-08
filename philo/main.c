/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:14:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/08 17:27:51 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *my_turn()
{
    int *kmi = (int *)malloc (sizeof (int));
    *kmi = 47;
    int i=0;
    while (i < 8)
    {
        sleep (1);
        printf ("my_turn>>>%d\n",*kmi);
        i++;
        (*kmi)++;
    }
    return (kmi);
}

void    *your_turn()
{
    int i =0;
    while (i < 5)
    {
        sleep(1);
        printf ("your_turn\n");
        i++;
    }
    return (NULL);
}

int main()
{
    pthread_t my;
    int *num;
    pthread_create (&my, NULL, &my_turn, NULL);
    // pthread_create (&you, NULL, &your_turn, NULL);
    // pthread_join (you, NULL);
    your_turn();
    pthread_join (my, (void *)&num);
    // while (1);
    // my_turn();
    printf ("finish <++%d++>\n",*num);
}