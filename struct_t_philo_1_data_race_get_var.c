/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_t_philo_1_data_race_get_var.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:42:21 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:42:27 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	get_id(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->id));
}

int	get_flag_last_philosopher(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->flag_last_philosopher));
}

int	get_stop_dining_all_p(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->stop_dining_all_p));
}

int	get_nb_of_dinners(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->nb_of_dinners));
}

int	get_last_meal_time(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->last_meal_time));
}
