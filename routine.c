/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:46:10 by ynguyen           #+#    #+#             */
/*   Updated: 2023/08/05 18:35:36 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	who_takes_fork(t_philors *philoo)
{
	if (philoo->who % 2 == 0)
	{
		usleep(5);
		pthread_mutex_lock(&philoo->d->mutex_fork[philoo->left_fork]);
		ft_printf(philoo, "has taken a fork");
		pthread_mutex_lock(&philoo->d->mutex_fork[philoo->right_fork]);
		ft_printf(philoo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philoo->d->mutex_fork[philoo->right_fork]);
		ft_printf(philoo, "has taken a fork");
		pthread_mutex_lock(&philoo->d->mutex_fork[philoo->left_fork]);
		ft_printf(philoo, "has taken a fork");
	}
}

void	philo_is_eating(t_philors *philoo)
{
	pthread_mutex_lock(&philoo->d->mutex_check);
	ft_printf(philoo, "is eating");
	philoo->eat_count++;
	philoo->finish_eating = time_stamp();
	pthread_mutex_unlock(&philoo->d->mutex_check);
	philo_time(philoo->d, philoo->d->time_eat);
	pthread_mutex_unlock(&philoo->d->mutex_fork[philoo->right_fork]);
	pthread_mutex_unlock(&philoo->d->mutex_fork[philoo->left_fork]);
}

void	philo_is_sleeping(t_philors *philoo)
{
	ft_printf(philoo, "is sleeping");
	philo_time(philoo->d, philoo->d->time_sleep);
}

void	*routine(void *philor)
{
	t_philors	*philoo;

	philoo = (t_philors *)philor;
	if (philoo->who % 2 == 0)
		philo_time(philoo->d, philoo->d->time_eat / 10);
	while (!ft_deathhh(philoo->d, 0))
	{
		who_takes_fork(philoo);
		philo_is_eating(philoo);
		philo_is_sleeping(philoo);
		ft_printf(philoo, "is thinking");
	}
	return (NULL);
}
