#include "philo.h"
int     monitoring(t_sum *data)
{
    int i;

    i = 0;
    while(i < data->n_philos)
    {
        
    }
}
int    thread_me(t_sum *data)
{
    int i;

    pthread_mutex_init(&data->mutex_check, NULL);
    pthread_mutex_init(&data->mutex_print, NULL);
    i = 0;
    while(i < data->n_philos)
    {
        if (pthread_create(&data->struct_philos[i], NULL, &routine, NULL) != 0)
        {
            write(2, "Well.. Failed to create thread\n", 32);
            return (1);
        }
        i++;
    }
    i = 0;
    while(i < data->n_philos)
    {
        if (pthread_join(&data->struct_philos[i], NULL) != 0)
            return (1);
        i++;
    }
    return (0);
}
