#include "philo.h"

void set_nb_of_plumpy_philos(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->nb_of_plumpy_philos, value);
}

void set_stop_dining_all(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->stop_dining_all, value);
}

void set_nb_of_philosophers(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->nb_of_philosophers, value);
}

void set_flag_already_died(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect, &ptr->flag_already_died, value);
}
