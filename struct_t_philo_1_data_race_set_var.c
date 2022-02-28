/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_t_philo_1_data_race_set_var.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:43:13 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:43:17 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	set_id(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->id, value);
}

void	set_flag_last_philosopher(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->flag_last_philosopher, value);
}

void	set_stop_dining_all_p(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->stop_dining_all_p, value);
}

void	set_nb_of_dinners(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->nb_of_dinners, value);
}

void	set_last_meal_time(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->last_meal_time, value);
}
