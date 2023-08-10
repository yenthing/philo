/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:53:32 by ynguyen           #+#    #+#             */
/*   Updated: 2023/08/05 14:47:52 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argument(t_data *data, int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
	{
		write(2, "Error\n Invalid arguments!\n", 27);
		return (1);
	}
	i = 0;
	while (++i < ac)
	{
		if (check_digit(av[i]) || check_empty(av[i]))
		{
			write(2, "Error\n Invalid variable!\n", 26);
			return (1);
		}
	}
	if (init_data(data, ac, av))
	{
		write(2, "Error\n Invalid arguments!\n", 27);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (write(2, "Malloc failed, data!\n", 21), 1);
	if (check_argument(data, ac, av))
	{
		free(data);
		return (1);
	}
	if (thread_me(data))
	{
		write(2, "Error\nThread failed\n", 21);
		free(data);
		return (1);
	}
	free(data);
	return (0);
}
