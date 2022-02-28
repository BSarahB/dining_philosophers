/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_t_utils_1_data_race_set_var.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:44:22 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:44:29 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_t_to_die(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->t_to_die, value);
}

void	set_t_to_eat(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->t_to_eat, value);
}

void	set_t_to_sleep(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->t_to_sleep, value);
}

void	set_t_start(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->t_start, value);
}

void	set_nb_of_mandatory_meals(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->nb_of_mandatory_meals, \
						value);
}
