#include "philo.h"

void	*ft_start_routine666(void *arg)
{
	t_philo	*p;
	int		stop;
	char	*chrono_death;

	p = (t_philo *)arg;
	stop = 0;
	//ft_printf_debug("D%d starts 666\n",get_id(p));
	while (stop == 0)
	{
		pthread_mutex_lock(&(*p).ptr->mutex666);
		if ((curr_time() - get_last_meal_time(p)) >= (unsigned int)get_t_to_die(p->ptr))
		{
				chrono_death = ft_itoa((int)(curr_time() - get_t_start(p->ptr)));
				ft_call_ft_printf(p, 'D', chrono_death);
				ft_free_str(chrono_death);
				pthread_mutex_unlock(&(*p).ptr->mutex666);
				//ft_printf_debug("p : %d, meal_count = %d\n", get_id(p), get_nb_of_dinners(p));
		}
		else
			pthread_mutex_unlock(&(*p).ptr->mutex666);
		stop = get_stop_dining_all(p->ptr) + get_stop_dining_all_p(p);
	}
	//ft_printf_debug("D%d DETACHED END\n",(*p).id);
	return (NULL);
}

