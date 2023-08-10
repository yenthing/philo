/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:53:12 by ynguyen           #+#    #+#             */
/*   Updated: 2023/08/04 10:59:48 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(const char *nb)
{
	int		i;
	long	value;

	value = 0;
	i = 0;
	while (nb[i] == 32 || (nb[i] > 8 && nb[i] < 14))
		i++;
	while (nb[i] > 47 && nb[i] < 58)
	{
		if (value >= LONG_MAX)
			break ;
		value = value * 10 + (nb[i] - '0');
		i++;
	}
	return (value);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_empty(char *s)
{
	if (s && s[0] == '\0')
		return (1);
	return (0);
}
