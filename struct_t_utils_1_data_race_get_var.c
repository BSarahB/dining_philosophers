#include "philo.h"

int get_t_to_die(t_utils * ptr)
{
	return (read_protected_int(&ptr->mutex_protect,&ptr->t_to_die));
}

int get_t_to_eat(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect,&ptr->t_to_eat));
}

int	get_t_to_sleep(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect,&ptr->t_to_sleep));
}

int	get_t_start(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect,&ptr->t_start));
}

int	get_nb_of_mandatory_meals(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect,&ptr->nb_of_mandatory_meals));
}
