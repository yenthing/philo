#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	value;

	sign = 1;
	value = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		value = value * 10 + (nptr[i] - 48);
		i++;
	}
	return (value * sign);
}

int check_digit(char *s)
{
    int i;

    i = 0;
    if (s[0] == '-' || s[0] == '+')
        i++;
    if (s[i] == '-' || s[i] == '+')
        return (1);
    while(s[i] == '0')
        i++;
    if (s[i] <= '0' && s[i] >= '9')
        return (1);
    return (0);
}

int	check_limit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	if (ft_strlen(s + i) > 10)
		return (1);
	if (ft_strlen(s + i) == 10)
	{
		if (s[i] > '2')
			return (1);
		if (s[i] == '2')
		{
			if (s[0] == '-' && ft_strcmp(s + i, "2147483648") == 0)
				return (0);
			if (ft_strcmp(s + i, "2147483647") > 0)
				return (1);
		}
	}
	return (0);
}

void	*what_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	
	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
