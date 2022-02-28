/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_t_utils_2_data_race_set_var.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:47:42 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:47:47 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_nb_of_plumpy_philos(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->nb_of_plumpy_philos, value);
}

void	set_stop_dining_all(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->stop_dining_all, value);
}

void	set_nb_of_philosophers(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->nb_of_philosophers, value);
}

void	set_flag_already_died(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->flag_already_died, value);
}
