#include "philo.h"

void who_takes_fork(t_philors *philors)
{
    if (philors->who % 2 == 0)
    {
        pthread_mutex_lock(&philors->data->mutex_fork[philors->right_fork]);
        printf("Philo %d has taken a fork\n", philors->data->struct_philos);
        pthread_mutex_lock(&philors->data->mutex_fork[philors->left_fork]);
        printf("Philo %d has taken a fork\n", &philors->data->struct_philos);
    }
    else
    {
        pthread_mutex_lock(&philors->data->mutex_fork[philors->left_fork]);
        printf("Philo %d has taken a fork\n", philors->data->struct_philos);
        pthread_mutex_lock(&philors->data->mutex_fork[philors->right_fork]);
        printf("Philo %d has taken a fork\n", philors->data->struct_philos);
    }
}

void    philo_is_eating(t_philors *philoo)
{
    philoo->finish_eating = current_time() + philoo->data->time_eat;
    philoo->death_note = current_time() + philoo->data->time_die;
    printf("Philo is eating\n");
    while(current_time() < philoo->finish_eating)
    {
        if (current_time >= philoo->data->time_die)
        {
            pthread_mutex_lock(&philoo->data->mutex_check);
            philoo->data->dead++;
            pthread_mutex_unlock(&philoo->data->mutex_check);
            printf("Philo %i died\n", philoo->who);
        }
    }
    pthread_mutex_unlock(&philoo->data->mutex_fork[philoo->right_fork]);
    pthread_mutex_unlock(&philoo->data->mutex_fork[philoo->left_fork]);
}

void    philo_is_sleep(t_philors *philoo)
{
    int i;

    i = 0;
    while(i < philoo->data->n_philos)
    {
        printf("Philo %i is sleeping\n", philoo->who);
        count_time(philoo->data->time_sleep);
        while(current_time() < philoo->data->time_sleep)
        {
            if (current_time >= philoo->data->time_die)
            {
                pthread_mutex_lock(&philoo->data->mutex_check);
                philoo->data->dead++;
                pthread_mutex_unlock(&philoo->data->mutex_check);
                printf("Philo %i died\n", philoo->who);
            }
        }
        printf("Philo %i is thinking\n", philoo->who);
        usleep(100);
        i++;
    }
}

void    *routine(void *philor)
{
    t_philors *philoo;

    philoo = (t_philors *)philor;
    who_takes_fork(&philoo);
    philo_is_eating(&philoo);
    while (!philoo->data->dead)
    {
        if (philoo->eat_count >= 0)
        {
            philoo->eat_count++;
            philo_is_sleep(&philoo);
        }
        else if (philoo->eat_count < 0)
            break ;
    }
}
