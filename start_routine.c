#include "philo.h"

void	ft_redirect_philosopher_to_fork(t_philo *p, int n, int smallest_fork, int x) //nb philos pair
{
    if (get_nb_of_philosophers(p->ptr) % 2 == 0) //nb philos pair
	{
        if (n % 2 != 0 || get_flag_last_philosopher(p) == 1) //si philosophe id est impair
			ft_smallest_fork(p, n, smallest_fork, x);
		else
			ft_biggest_fork(p, n, smallest_fork, x);
	}
	else{
        if (n % 2 == 0 || get_flag_last_philosopher(p) == 1 || n == 1)//id pair, dernier philosoph ou premier vont chopper le smallest fourchette
			ft_smallest_fork(p, n, smallest_fork, x);
		else
			ft_biggest_fork(p, n, smallest_fork, x);
		}
}

void	ft_sleep_and_think(t_philo *p, int n)
{
	char *chrono_sleep;
	char *chrono_think;

    chrono_sleep = ft_itoa((int)(curr_time() - get_t_start(p->ptr)));
    ft_printf("%s %d is sleeping\n",chrono_sleep, n);
	ft_free_str(chrono_sleep);
    ft_call_usleep(get_t_to_sleep(p->ptr));
    if (get_stop_dining_all(p->ptr) != 1)
	{
        chrono_think = ft_itoa((int)(curr_time() - get_t_start(p->ptr)));
        ft_printf("%s %d is thinking \n",chrono_think, n);
		usleep(100);
		ft_free_str(chrono_think);
	}
}

void *ft_start_routine(void *arg)
{
	t_philo	*p;
	int		n;
	int		x;
	int		smallest_fork;

	p = (t_philo *)arg;
//	pthread_create(&p->D, NULL, (void *)ft_start_routine666, p);

    ft_printf("P%d after ft_call_death in start_routine\n",get_id(p));
    while (get_stop_dining_all(p->ptr) == 0)
	{
        n = get_id((t_philo *)arg);
        x = get_id((t_philo *)arg);
		smallest_fork = n - 1;
        if (get_flag_last_philosopher((t_philo *)arg) == 1)
		{
			smallest_fork = 0;
			x = n - 1;
		}
		else
			x = n;
        if (get_stop_dining_all(p->ptr) == 0)
			ft_redirect_philosopher_to_fork(p, n, smallest_fork, x);
        if (get_stop_dining_all(p->ptr) == 0)
			ft_sleep_and_think(p, n);
	}
    ft_printf("P%d send_of_start_routine\n",get_id(p));
	return (NULL);
}
