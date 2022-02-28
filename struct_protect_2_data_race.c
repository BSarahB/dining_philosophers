#include "philo.h"

pthread_t read_protected_pthread_t(pthread_mutex_t *mutex, pthread_t *var)
{
	return (*read_protected_pthread_t_star(mutex, var));
}

pthread_t *read_protected_pthread_t_star(pthread_mutex_t *mutex, pthread_t *var)
{
	pthread_t *value;

	pthread_mutex_lock(mutex);
	value = var;
	pthread_mutex_unlock(mutex);
	return (value);
}

void write_protected_pthread_t(pthread_mutex_t *mutex, pthread_t *var, \
							const pthread_t value)
{
	pthread_mutex_lock(mutex);
	*var = value;
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
