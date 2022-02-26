#include "philo.h"

int read_protected_int(pthread_mutex_t *mutex, int *var)
{
	return (*read_protected_int_star(mutex, var));
}

int *read_protected_int_star(pthread_mutex_t * mutex, int *var)
{
	int *value ;

	value = NULL;
	pthread_mutex_lock(mutex);
	value = var;
	pthread_mutex_unlock(mutex);
	return (value);
}

void write_protected_int(pthread_mutex_t *mutex, int *var, const int value)
{
	pthread_mutex_lock(mutex);
	*var = value ;
	pthread_mutex_unlock(mutex);
}

pthread_t read_protected_pthread_t(pthread_mutex_t *mutex, pthread_t *var)
{
	return (*read_protected_pthread_t_star(mutex, var));
}

pthread_t *read_protected_pthread_t_star(pthread_mutex_t * mutex, pthread_t *var)
{
	pthread_t *value ;

	pthread_mutex_lock(mutex);
	value = var;
	pthread_mutex_unlock(mutex);
	return (value);
}

void write_protected_pthread_t(pthread_mutex_t *mutex, pthread_t *var, const pthread_t value)
{
	pthread_mutex_lock(mutex);
	*var = value ;
	pthread_mutex_unlock(mutex);
}

t_utils read_protected_t_utils(pthread_mutex_t *mutex, t_utils *var)
{
	return (*read_protected_t_utils_star(mutex, var));
}

t_utils *read_protected_t_utils_star(pthread_mutex_t *mutex, t_utils *var)
{
	t_utils *value;

	pthread_mutex_lock(mutex);
	value = var;
	pthread_mutex_unlock(mutex);
	return (value);
}

void write_protected_t_utils(pthread_mutex_t * mutex, t_utils *var, const t_utils value)
{
	pthread_mutex_lock(mutex);
	*var = value ;
	pthread_mutex_unlock(mutex);
}

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

int	get_nb_of_plumpy_philos(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect,&ptr->nb_of_plumpy_philos));
}

int	get_stop_dining_all(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect,&ptr->stop_dining_all));
}

int	get_nb_of_philosophers(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect,&ptr->nb_of_philosophers));
}

int	get_flag_already_died(t_utils *ptr)
{
	return (read_protected_int(&ptr->mutex_protect,&ptr->flag_already_died));
}

void set_t_to_die(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect,&ptr->t_to_die, value);
}

void set_t_to_eat(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect,&ptr->t_to_eat, value);
}

void set_t_to_sleep(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect,&ptr->t_to_sleep, value);
}

void set_t_start(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect,&ptr->t_start, value);
}

void set_nb_of_mandatory_meals(t_utils *ptr, int value)
{
	write_protected_int(&ptr->mutex_protect,&ptr->nb_of_mandatory_meals, value);
}

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

void set_id(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->id, value);
}

void set_flag_last_philosopher(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->flag_last_philosopher, value);
}

void set_stop_dining_all_p(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->stop_dining_all_p, value);
}

void set_nb_of_dinners(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->nb_of_dinners, value);
}

void set_last_meal_time(t_philo *p, int value)
{
	write_protected_int(&p->mutex_protect, &p->last_meal_time, value);
}
