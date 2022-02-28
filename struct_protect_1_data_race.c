/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_protect_1_data_race.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:40:06 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:40:11 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	*read_protected_int_star(pthread_mutex_t *mutex, int *var)
{
	int	*value ;

	pthread_mutex_lock(mutex);
	value = var;
	pthread_mutex_unlock(mutex);
	return (value);
}

int	read_protected_int(pthread_mutex_t *mutex, int *var)
{
	return (*read_protected_int_star(mutex, var));
}

void	write_protected_int(pthread_mutex_t *mutex, int *var, const int value)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}

void	write_protected_t_utils(pthread_mutex_t *mutex, t_utils *var, \
							const t_utils value)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}
