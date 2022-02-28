#include "philo.h"

int	get_nb_of_plumpy_philos(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect, &ptr->nb_of_plumpy_philos));
}

int	get_stop_dining_all(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect, &ptr->stop_dining_all));
}

int	get_nb_of_philosophers(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect, &ptr->nb_of_philosophers));
}

int	get_flag_already_died(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect, &ptr->flag_already_died));
}
