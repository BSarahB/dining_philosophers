/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_free_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:56:09 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:56:13 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_free_malloc_threads_p(pthread_t *th_p)
{
	if (th_p != NULL)
	{
		free(th_p);
		th_p = NULL;
	}
}

void	ft_free_malloc_mutex_f(pthread_mutex_t *forks)
{
	if (forks != NULL)
	{
		free(forks);
		forks = NULL;
	}
}

void	ft_free_struct_t_ptr(t_utils **ptr)
{
	ft_free_malloc_mutex_f((*ptr)->forks);
	ft_free_malloc_threads_p((*ptr)->th_p);
	ft_free_malloc_threads_p((*ptr)->th_d);
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_struct_t_philo(t_philo **p)
{
	ft_free_struct_t_ptr(&((*p)->ptr));
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

void	ft_free_struct_t_philo_only(t_philo **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
