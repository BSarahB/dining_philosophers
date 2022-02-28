/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_t_utils_1_data_race_get_var.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:45:18 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:45:21 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	get_t_to_die(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect, &ptr->t_to_die));
}

int	get_t_to_eat(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect, &ptr->t_to_eat));
}

int	get_t_to_sleep(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect, &ptr->t_to_sleep));
}

int	get_t_start(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect, &ptr->t_start));
}

int	get_nb_of_mandatory_meals(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect, \
							&ptr->nb_of_mandatory_meals));
}
