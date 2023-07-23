#include "philo.h"

int main(int ac, char **av)
{
    t_sum data;
    if (ac < 5 || ac > 6)
    {
        write(2, "Ups! Arguments are invalid!\n", 29);
        return (1);
    }
    if (init_data(&data, ac, av))
    {
        ft_free(&data);
        return (1);
    }
    // valerian was here hehe
    pthread_mutex_init(data.mutex_check, NULL);
    pthread_mutex_init(data.mutex_print, NULL);
    if (pthread_create(&data.struct_philos, NULL, &routine, NULL) != 0)
    {
        write(2, "Well.. Failed to create thread\n", 32);
        return (1);
    }
    if (pthread_join(&data.struct_philos, NULL) != 0)
        return (1);
    return (0);
}