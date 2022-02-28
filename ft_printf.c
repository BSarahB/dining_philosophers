#include "philo.h"

void	ft_call_ft_printf(t_philo *p, char c, char *chrono)
{
	pthread_mutex_lock(&(*p).ptr->mutex_printf);
	if (get_stop_dining_all(p->ptr) == 1)
	{
		pthread_mutex_unlock(&(*p).ptr->mutex_printf);
		return ;
	}
	if (c == 'D')
		set_stop_dining_all(p->ptr, 1);
	if (c == 'D')
		printf("%s %d DIED\n", chrono, get_id(p));
	else if (c == 'F')
		printf("%s %d has taken a fork\n", chrono, get_id(p));
	else if(c == 'E')
		printf("%s %d is eating\n", chrono, get_id(p));
	else if (c == 'S')
		printf("%s %d is sleeping\n",chrono, get_id(p));
	else if(c == 'T')
		printf("%s %d is thinking\n",chrono, get_id(p));
	pthread_mutex_unlock(&(*p).ptr->mutex_printf);
}
