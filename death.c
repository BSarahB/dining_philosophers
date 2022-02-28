/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:13:35 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:13:40 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*ft_start_routine666(void *arg)
{
	t_philo	*p;
	int		stop;
	char	*chrono_death;

	p = (t_philo *)arg;
	stop = 0;
	while (stop == 0)
	{
		pthread_mutex_lock(&(*p).ptr->mutex666);
		if ((curr_time() - get_last_meal_time(p)) >= \
				(unsigned int)get_t_to_die(p->ptr))
		{
			chrono_death = ft_itoa((int)(curr_time() - \
										get_t_start(p->ptr)));
			ft_call_ft_printf(p, 'D', chrono_death);
			ft_free_str(chrono_death);
			pthread_mutex_unlock(&(*p).ptr->mutex666);
		}
		else
			pthread_mutex_unlock(&(*p).ptr->mutex666);
		pthread_mutex_lock(&(*p).ptr->mutex_printf);
		stop = get_stop_dining_all(p->ptr) + get_stop_dining_all_p(p);
		pthread_mutex_unlock(&(*p).ptr->mutex_printf);
	}
	return (NULL);
}
