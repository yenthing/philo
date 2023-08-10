/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:02:33 by ynguyen           #+#    #+#             */
/*   Updated: 2023/08/05 16:42:10 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_printf(t_philors *ph, char *str)
{
	pthread_mutex_lock(&ph->d->mutex_print);
	if (!ft_strcmp(str, "died"))
	{
		printf("%lli %i %s\n", time_stamp() - ph->d->start_time, ph->who, str);
		pthread_mutex_unlock(&ph->d->mutex_print);
		return (1);
	}
	if (ft_deathhh(ph->d, 0))
	{
		pthread_mutex_unlock(&ph->d->mutex_print);
		return (1);
	}
	printf("%lli %i %s\n", time_stamp() - ph->d->start_time, ph->who, str);
	pthread_mutex_unlock(&ph->d->mutex_print);
	return (0);
}
