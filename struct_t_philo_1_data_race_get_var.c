#include "philo.h"

int get_id(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->id));
}

int get_flag_last_philosopher(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->flag_last_philosopher));
}

int get_stop_dining_all_p(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->stop_dining_all_p));
}

int get_nb_of_dinners(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->nb_of_dinners));
}

int get_last_meal_time(t_philo *p)
{
	return (read_protected_int(&p->mutex_protect, &p->last_meal_time));
}
