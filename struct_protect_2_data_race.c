/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_protect_2_data_race.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:41:07 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:41:12 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

pthread_t	read_protected_pthread_t(pthread_mutex_t *mutex, pthread_t *var)
{
	return (*read_protected_pthread_t_star(mutex, var));
}

pthread_t	*read_protected_pthread_t_star(pthread_mutex_t *mutex, \
										pthread_t *var)
{
	pthread_t	*value;

	pthread_mutex_lock(mutex);
	value = var;
	pthread_mutex_unlock(mutex);
	return (value);
}

void	write_protected_pthread_t(pthread_mutex_t *mutex, pthread_t *var, \
							const pthread_t value)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}

t_utils	read_protected_t_utils(pthread_mutex_t *mutex, t_utils *var)
{
	return (*read_protected_t_utils_star(mutex, var));
}

t_utils	*read_protected_t_utils_star(pthread_mutex_t *mutex, t_utils *var)
{
	t_utils	*value;

	pthread_mutex_lock(mutex);
	value = var;
	pthread_mutex_unlock(mutex);
	return (value);
}
