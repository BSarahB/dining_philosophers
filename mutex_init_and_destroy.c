/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init_and_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:50:55 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 06:50:57 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_free_separately(t_philo *philos, t_utils *ptr)
{
	ft_free_struct_t_ptr(&ptr);
	ft_free_struct_t_philo_only(&philos);
}

int	ft_mutex_destroy(t_utils *ptr, t_philo *philos, pthread_mutex_t *f, int p)
{
	int	k;
	int	kk;

	while (p < get_nb_of_philosophers(ptr))
	{
		k = pthread_mutex_destroy(&f[p]);
		if (k != 0)
			printf("Mutex F not Destroyed for %d\n", get_id(&philos[p]));
		kk = pthread_mutex_destroy(&philos[p].mutex_protect);
		if (kk != 0)
			printf("Mutex_protect not Destroyed for %d\n", get_id(&philos[p]));
		if (k != 0 || kk != 0)
		{
			ft_mutex_destroy(ptr, philos, f, p + 1);
			ft_free_struct_t_philo(&philos);
			return (1);
		}
		p++;
	}
	pthread_mutex_destroy(&ptr->mutex666);
	pthread_mutex_destroy(&ptr->mutex_printf);
	pthread_mutex_destroy(&ptr->mutex_protect);
	return (0);
}

int	ft_mutex_init(t_utils *ptr, pthread_mutex_t *f, t_philo *philos)
{
	int	i;
	int	k;

	i = -1;
	k = pthread_mutex_init(&ptr->mutex666, NULL);
	if (k == -1)
		ft_error("Mutex_666 initialization failed\n");
	k = pthread_mutex_init(&ptr->mutex_printf, NULL);
	if (k == -1)
		ft_error("Mutex_printf initialization failed\n");
	k = pthread_mutex_init(&ptr->mutex_protect, NULL);
	if (k == -1)
		ft_error("Mutex_protect of ptr initialization failed\n");
	while (++i < get_nb_of_philosophers(ptr))
	{
		k = pthread_mutex_init(&f[i], NULL);
		if (k == -1)
			ft_error("Mutex F initialization failed\n");
	}
	if (k == -1)
	{
		ft_free_separately(philos, ptr);
		return (1);
	}
	return (0);
}
