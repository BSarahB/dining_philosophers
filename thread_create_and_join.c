/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create_and_join.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:00:47 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 06:00:50 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_destroy_and_free(t_philo *philos, t_utils *ptr)
{
	ft_mutex_destroy(ptr, philos, (*ptr).forks, 0);
	ft_free_struct_t_philo(&philos);
}

int	ft_thread_join(t_utils *ptr, pthread_t *th_p, pthread_t *th_d, \
				t_philo *philos)
{
	int	l;
	int	w;
	int	ww;

	l = 0;
	while (l < get_nb_of_philosophers(ptr))
	{
		w = pthread_join(th_p[l], NULL);
		if (w != 0)
			printf("Thread P join failed \n");
		ww = pthread_join(th_d[l], NULL);
		if (ww != 0)
			printf("Thread D join failed \n");
		if (w || ww)
		{
			ft_mutex_destroy(ptr, philos, (*ptr).forks, 0);
			ft_free_struct_t_philo(&philos);
			return (1);
		}
		l++;
	}
	return (0);
}

int	ft_thread_create(t_utils *ptr, t_philo *philos, pthread_t *th_p, \
					pthread_t *th_d)
{
	int	j;
	int	k;

	j = -1;
	while (++j < get_nb_of_philosophers(ptr))
	{
		set_last_meal_time(&philos[j], curr_time());
		k = pthread_create(&th_p[j], NULL, (void *)ft_start_routine, \
						&philos[j]);
		if (k != 0)
		{
			printf("Thread_p (philosophers) creation error \n");
			ft_destroy_and_free(philos, ptr);
			return (1);
		}
		k = pthread_create(&th_d[j], NULL, (void *)ft_start_routine666, \
						&philos[j]);
		if (k != 0)
		{
			printf("Thread_d (death) creation error \n");
			ft_destroy_and_free(philos, ptr);
			return (1);
		}
	}
	return (0);
}
