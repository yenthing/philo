
#include "philo.h"

int check_variable(t_sum *data, int ac, char **av)
{
    int i;

    if (data->n_philos < 1 || data->n_philos > 200)
    {
        write(1, "Philosophers are not authorized!", 33);
        return (1);
    }
    if (data->start_time < 0 || data->time_die < 0 || data->time_eat < 0)
    {
        write(1, "Time is not authorized!", 33);
        return (1);
    }
    if (data->time_sleep < 0)
    {
        write(1, "Time is not authorized!", 33);
        return (1);
    }
    i = 0;
    while (++i < ac)
    {
        if (check_limit(av[i]) || check_digit(av[i]))
            return (1);
    }
    return (0);
}

int   init_philors(t_sum *data)
{
    int i;

    i = 0;
    data->struct_philos = malloc(sizeof(t_philors) * data->n_philos);
    if (!data->struct_philos)
        return (1);
    data->mutex_fork = malloc(sizeof(pthread_mutex_t) * data->n_philos);
    if (!data->mutex_fork)
        return (1);
    while(i < data->n_philos)
    {
        data->struct_philos[i].who = i + 1;
        data->struct_philos[i].left_fork = i;
        if (i == data->n_philos - 1)
            data->struct_philos[0].right_fork = 0;
        else
            data->struct_philos[i].right_fork = i + 1;
        data->struct_philos[i].eat_count = 0;
        data->struct_philos[i].finish_eating = 0;
        data->struct_philos[i].death_note = 0;
        data->struct_philos[i].data = data;
        i++;
    }
    return (0);
}

int free_init(pthread_mutex_t *a, pthread_mutex_t *b, pthread_mutex_t *c)
{
    if (a)
        free(a);
    if (b)
        free(b);
    if (c)
        free(c);
    return (1);
}

int    init_mutex(t_sum *data, int ac, char **av)
{
    data->mutex_fork = malloc(sizeof(pthread_mutex_t) * data->n_philos);
    if (!data->mutex_fork)
        return (1);
    data->mutex_check = malloc(sizeof(pthread_mutex_t) * 1);
    if (!data->mutex_check)
        return (free_init(data->mutex_fork, NULL, NULL));
    data->mutex_print = malloc(sizeof(pthread_mutex_t) * 1);
    if (!data->mutex_print)
        return (free_init(data->mutex_fork, data->mutex_check, NULL));
    data->struct_philos = malloc(sizeof(t_philors) * data->n_philos);
    if (!data->struct_philos)
        return (free_init(data->mutex_fork, data->mutex_check, data->mutex_print));
    return (0);
}

int init_data(t_sum *data, int ac, char **av)
{
    data->error = NULL;
    data->dead = NULL;
    data->full = NULL;
    data->n_philos = ft_atoi(av[1]);
    data->time_die = ft_atoi(av[2]);
    data->time_eat = ft_atoi(av[3]);
    data->time_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->n_times_to_eat = ft_atoi(av[5]);
    else if (ac < 6)
        data->n_times_to_eat = -1;
    if (check_variable(data, ac, av) != 0)
        return (1);
    if (init_philors(data) != 0)
        return (1);
    if (init_mutex(data, ac , av) != 0)
        return (1);
    return (0);
}