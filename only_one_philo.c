/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:23:21 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:23:28 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_only_one_philo(t_utils *ptr, t_philo *philos)
{
	char	*chrono;

	if (get_nb_of_philosophers(ptr) == 1)
	{
		ft_call_usleep(get_t_to_die(ptr));
		chrono = ft_itoa((int)(curr_time() - get_t_start(ptr)));
		printf("%s %d died\n", chrono, get_nb_of_philosophers(ptr));
		ft_mutex_destroy(ptr, philos, ptr->forks, 0);
		ft_free_struct_t_philo(&philos);
		ft_free_str(chrono);
		return (1);
	}
	return (0);
}
