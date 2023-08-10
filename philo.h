/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:53:24 by ynguyen           #+#    #+#             */
/*   Updated: 2023/08/05 17:08:07 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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
	struct s_data	*d;
}					t_philors;

typedef struct s_data
{
	int				n_of_philos;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				n_times_to_eat;
	int				dead;
	int				eat_all;
	long long		start_time;
	pthread_mutex_t	mutex_check;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_dead;
	t_philors		*struct_philos;
}					t_data;

//free.c
int					ft_deathhh(t_data *d, int i);
int					free_init(pthread_mutex_t *a);

//ft_printf.c
int					ft_printf(t_philors *philor, char *str);

//init_data.c
int					init_data(t_data *data, int ac, char **av);

//main.c
int					check_argument(t_data *data, int ac, char **av);

//routine.c
void				*routine(void *philor);

//thread.c
int					ft_deathhh(t_data *d, int i);
int					thread_me(t_data *data);

//time.c
long long			time_stamp(void);
void				philo_time(t_data *d, long long time);

//utils.c
int					ft_strlen(char *str);
long				ft_atoi(const char *nb);
int					ft_strcmp(char *s1, char *s2);
int					check_digit(char *s);
int					check_empty(char *s);
#endif