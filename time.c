#include "philo.h"

long    current_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL))
        return (0);
    return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

int count_time(long now)
{
    while(1)
    {
        if (current_time() > now)
            return (0);
    }
}