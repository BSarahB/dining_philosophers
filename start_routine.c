#include "philo.h"

void	ft_redirect_philosopher_to_fork(t_philo *p, int n, int smallest_fork, int big_fork)
{
	if (get_nb_of_philosophers(p->ptr) % 2 == 0) //nb philos pair
	{
		if (n % 2 != 0 || get_flag_last_philosopher(p) == 1) //si philosophe id est impair
			ft_smallest_fork(p, smallest_fork, big_fork);
		else
			ft_biggest_fork(p, smallest_fork, big_fork);
	}
	else
	{
		if (n % 2 == 0 || get_flag_last_philosopher(p) == 1 || n == 1)//id pair, dernier philosoph ou premier vont chopper le smallest fourchette
			ft_smallest_fork(p, smallest_fork, big_fork);
		else
			ft_biggest_fork(p, smallest_fork, big_fork);
	}
}

void	ft_sleep_and_think(t_philo *p)
{
	char *chrono_sleep;
	char *chrono_think;

	chrono_sleep = ft_itoa((int)(curr_time() - get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'S', chrono_sleep);
	ft_free_str(chrono_sleep);
	ft_call_usleep(get_t_to_sleep(p->ptr));
	chrono_think = ft_itoa((int)(curr_time() - get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'T', chrono_think);
	if(get_nb_of_philosophers(p->ptr) % 2 != 0)
		ft_call_usleep(100);
	ft_free_str(chrono_think);
}

void	ft_positioning_forks_and_philos(t_philo *p)
{
	int		n;
	int		big_fork;
	int		smallest_fork;

	n = get_id(p);
	big_fork = get_id(p);
	smallest_fork = n - 1;
	if (get_flag_last_philosopher(p) == 1)
	{
		smallest_fork = 0;
		big_fork = n - 1;
	}
	else
		big_fork = n;
	ft_redirect_philosopher_to_fork(p, n, smallest_fork, big_fork);
	if (get_nb_of_mandatory_meals(p->ptr) != -1 && get_nb_of_dinners(p) == get_nb_of_mandatory_meals(p->ptr))
	{
		ft_printf_debug("dans la check mandatory meals avec p: %d - avec nb_of_dinners: %d\n", get_id(p), get_nb_of_dinners(p));
		set_stop_dining_all_p(p, 1);
		return;
	}
	ft_sleep_and_think(p);
}

void *ft_start_routine(void *arg)
{
	t_philo	*p;
	int		stop;

	stop = 0;
	p = (t_philo *)arg;
	//ft_printf_debug("P%d after ft_call_death in start_routine\n",get_id(p));
	while(stop == 0)
	{
		ft_positioning_forks_and_philos(p);
		stop = get_stop_dining_all(p->ptr) + get_stop_dining_all_p(p);
	}
	//ft_printf_debug("P%d end_of_start_routine\n",get_id(p));
	return (NULL);
}
