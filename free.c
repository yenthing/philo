/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:56:16 by ynguyen           #+#    #+#             */
/*   Updated: 2023/08/02 18:33:36 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_deathhh(t_data *d, int i)
{
	pthread_mutex_lock(&d->mutex_dead);
	if (i)
		d->dead = 1;
	if (d->dead)
	{
		pthread_mutex_unlock(&d->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&d->mutex_dead);
	return (0);
}

int	free_init(pthread_mutex_t *a)
{
	if (a)
		free(a);
	return (1);
}
