/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:56:50 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:56:52 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_free_str(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

int	find_length(int n)
{
	int	length;

	if (n <= 0)
		length = 1;
	else
		length = 0;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;
	long	nb;

	nb = n;
	length = find_length(n);
	result = (char *)malloc(sizeof(*result) * length + 1);
	if (!result)
		return (NULL);
	result[length] = '\0';
	if (nb < 0)
		result[0] = '-';
	else if (nb == 0)
		result[0] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		--length;
		result[length] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (result);
}

long	ft_atoi(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' \
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	result = sign * result;
	return (result);
}
