/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:15:23 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:15:26 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_check_int_max(int argc, char **argv)
{
	int		i;
	long	n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

void	ft_error(char *const str)
{
	ft_putstr_fd(str, 2);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_check_error(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
