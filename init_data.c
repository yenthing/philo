/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:53:39 by ynguyen           #+#    #+#             */
/*   Updated: 2023/08/05 17:22:53 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_variable(t_data *data)
{
	if (data->n_of_philos < 1 || data->n_of_philos > 200)
		return (1);
	if (data->start_time < 0 || data->time_die <= 0 || data->time_eat <= 0)
		return (1);
	if (data->time_sleep <= 0)
		return (1);
	return (0);
}

int	init_philors(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_of_philos)
	{
		data->struct_philos[i].who = i + 1;
		data->struct_philos[i].left_fork = i;
		if (i == data->n_of_philos - 1)
			data->struct_philos[i].right_fork = 0;
		else
			data->struct_philos[i].right_fork = i + 1;
		data->struct_philos[i].eat_count = 0;
		data->struct_philos[i].finish_eating = 0;
		data->struct_philos[i].death_note = 0;
		data->struct_philos[i].d = data;
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->mutex_check, NULL))
		return (1);
	if (pthread_mutex_init(&data->mutex_print, NULL))
		return (1);
	if (pthread_mutex_init(&data->mutex_dead, NULL))
		return (1);
	while (i < data->n_of_philos)
	{
		if (pthread_mutex_init(&data->mutex_fork[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	malloc_mutex(t_data *data)
{
	data->mutex_fork = malloc(sizeof(pthread_mutex_t) * data->n_of_philos);
	if (!data->mutex_fork)
		return (1);
	data->struct_philos = malloc(sizeof(t_philors) * data->n_of_philos);
	if (!data->struct_philos)
		return (free_init(data->mutex_fork));
	if (init_mutex(data))
		return (free_init(data->mutex_fork));
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->dead = 0;
	data->eat_all = 0;
	data->start_time = 0;
	data->n_of_philos = (int)ft_atoi(av[1]);
	data->time_die = (int)ft_atoi(av[2]);
	data->time_eat = (int)ft_atoi(av[3]);
	data->time_sleep = (int)ft_atoi(av[4]);
	if (ac == 6)
	{
		data->n_times_to_eat = ft_atoi(av[5]);
		if (data->n_times_to_eat <= 0)
			return (1);
	}
	else if (ac < 6)
		data->n_times_to_eat = -1;
	if (check_variable(data))
		return (1);
	if (malloc_mutex(data))
		return (1);
	if (init_philors(data))
		return (1);
	return (0);
}
