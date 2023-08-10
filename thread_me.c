/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_me.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:53:02 by ynguyen           #+#    #+#             */
/*   Updated: 2023/08/05 18:34:24 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *philor)
{
	t_philors	*philoo;

	philoo = (t_philors *)philor;
	philoo->d->start_time = time_stamp();
	pthread_mutex_lock(&philoo->d->mutex_fork[philoo->left_fork]);
	ft_printf(philoo, "has taken a fork");
	while (!ft_deathhh(philoo->d, 0))
		usleep(50);
	pthread_mutex_unlock(&philoo->d->mutex_fork[philoo->left_fork]);
	return (NULL);
}

int	all_eat(t_data *data, int i)
{
	if (data->n_times_to_eat == -1)
		return (0);
	if (data->struct_philos[i].eat_count >= data->n_times_to_eat)
	{
		data->eat_all++;
		if (data->eat_all == data->n_of_philos)
		{
			ft_deathhh(data, 1);
			return (1);
		}
	}
	return (0);
}

void	check_thread(t_data *d)
{
	int	i;

	while (1)
	{
		i = -1;
		d->eat_all = 0;
		while (++i < d->n_of_philos && !ft_deathhh(d, 0))
		{
			pthread_mutex_lock(&d->mutex_check);
			if (all_eat(d, i) == 1)
			{
				pthread_mutex_unlock(&d->mutex_check);
				return ;
			}
			if (time_stamp() - d->struct_philos[i].finish_eating > d->time_die)
			{
				ft_deathhh(d, 1);
				ft_printf(&d->struct_philos[i], "died");
				pthread_mutex_unlock(&d->mutex_check);
				return ;
			}
			pthread_mutex_unlock(&d->mutex_check);
			usleep(100);
		}
	}
}

int	join_thread(t_data *data, int nb_thread)
{
	int	i;

	i = 0;
	while (i < data->n_of_philos && i < nb_thread)
	{
		if (pthread_join(data->struct_philos[i].thread_id, NULL))
		{
			write(2, "Error\nCant join thread\n", 23);
			return (1);
		}
		i++;
	}
	i = -1;
	while (++i < data->n_of_philos && i < nb_thread)
		pthread_mutex_destroy(&data->mutex_fork[i]);
	pthread_mutex_destroy(&data->mutex_check);
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_dead);
	free(data->mutex_fork);
	free(data->struct_philos);
	return (1);
}

int	thread_me(t_data *data)
{
	int	i;

	i = 0;
	if (data->n_of_philos == 1)
	{
		pthread_create(&data->struct_philos[0].thread_id, NULL, one_philo,
			&data->struct_philos[0]);
		data->struct_philos[0].finish_eating = time_stamp();
	}
	else
	{
		data->start_time = time_stamp();
		while (i < data->n_of_philos)
		{
			data->struct_philos[i].finish_eating = time_stamp();
			if (pthread_create(&data->struct_philos[i].thread_id, NULL,
					&routine, &data->struct_philos[i]))
				return (join_thread(data, i));
			i++;
		}
	}
	check_thread(data);
	join_thread(data, data->n_of_philos);
	return (0);
}
