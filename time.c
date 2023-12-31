/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:53:07 by ynguyen           #+#    #+#             */
/*   Updated: 2023/08/05 15:13:35 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_stamp(void)
{
	struct timeval	real_time;
	long long		time;

	gettimeofday(&real_time, NULL);
	time = real_time.tv_sec * 1000 + real_time.tv_usec / 1000;
	return (time);
}

void	philo_time(t_data *d, long long time)
{
	long long	start;

	start = time_stamp();
	while (time_stamp() - start < time)
	{
		if (ft_deathhh(d, 0))
			return ;
		usleep(10);
	}
}
