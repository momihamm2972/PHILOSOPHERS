/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:14:44 by momihamm          #+#    #+#             */
/*   Updated: 2023/10/25 01:40:51 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int merma = 0;
pthread_mutex_t k_9fel;

// void    *my_turn()
// {
//     int *kmi = (int *)malloc (sizeof (int));
//     *kmi = 47;
//     int i=0;
//     while (i < 8)
//     {
//         sleep (1);
//         printf ("my_turn>>>%d\n",*kmi);
//         i++;
//         (*kmi)++;
//     }
//     return (kmi);
// }

// void    *your_turn()
// {
//     int i =0;
//     while (i < 5)
//     {
//         sleep(1);
//         printf ("your_turn\n");
//         i++;
//     }
//     return (NULL);
// }

void    *rotine()
{
    int indx;

    indx = 0;
    // if (lock == 0)
    // {
    while (indx < 1000000000)
    {
        pthread_mutex_lock(&k_9fel);
        merma++;
        indx++;
        pthread_mutex_unlock(&k_9fel);
    }
    // }
    return (NULL);
}
// last meal dyal lowlani makayt updatach fmera;
// katchi ghir dethe f node lwela ya3eni maka tchikich ga3 lfalasifa;
// fach imot chi wa7ed exity;
void    ft_usleep(long time)
{
    long    current;

    current = ft_now();
    while((ft_now -  current) < (time * 1000))
    {
        usleep(10);
    }
}

int main()
{
    // pthread_t my, you;
    // pthread_mutex_init(&k_9fel, NULL);
    // // int *num;
    // pthread_create (&my, NULL, &rotine, NULL);
    // pthread_create (&you, NULL, &rotine, NULL);
    // pthread_join (my, NULL);
    // pthread_join (you, NULL);
    // pthread_mutex_destroy (&k_9fel);
    // your_turn();
    // while (1);
    // my_turn();
    struct timeval time;
    gettimeofday (&time, NULL);
    // printf ("finish <++%d++>\n",gettimeofday (&time, NULL));
    // printf ("finish <++%d++>\n",gettimeofday (&time, NULL));
    // int i =0;
    // while (i < 1000)
    printf ("finish <++%ld++>\n",time.tv_sec);
    printf ("finish <++%d++>\n",time.tv_usec);
    printf ("finish <++%ld++>\n",(time.tv_sec * 1000000000) + time.tv_usec);
    //     i++;
    sleep (1);
    // tv_usec
    printf ("finish <++%ld++>\n",time.tv_sec);
    printf ("finish <++%d++>\n",time.tv_usec);
    printf ("finish <++%ld++>\n",(time.tv_sec * 1000000000) + time.tv_usec);
    // printf ("finish <++%d++>\n",gettimeofday (&time, NULL));
}