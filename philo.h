# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_philors
{
	unsigned int	who;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	int				eating;
	long			finish_eating;
	long			death_note;
	pthread_t		thread_id;
	struct s_sum	*data;
}					t_philors;

typedef struct      s_sum
{
	unsigned int			n_philos;
	long					time_die;
	long					time_eat;
	long					time_sleep;
	int						n_times_to_eat;
	int						dead;
	int						full;
	int						error;
	long long				start_time;
	pthread_mutex_t			*mutex_check;
	pthread_mutex_t			*mutex_print;
	pthread_mutex_t			*mutex_fork;
	t_philors				*struct_philos;
}							t_sum;

//routine.c
void *routine(void *philor);

//thread.c
int		thread_me(t_sum *data);
int		check_mutex_fork(t_sum *data, int ac, char **av);

#endif