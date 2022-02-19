#include "philo.h"

void	ft_redirect_philosopher_to_fork(t_philo *p, int n, int smallest_fork, int x) //nb philos pair
{
	if ((*p).ptr->nb_of_philosophers % 2 == 0) //nb philos pair
	{
		if (n % 2 != 0 || (*p).flag_last_philosopher == 1) //si philosophe id est impair
			ft_smallest_fork(p, n, smallest_fork, x);
		else
			ft_biggest_fork(p, n, smallest_fork, x);
	}
	else{
		if (n % 2 == 0 || (*p).flag_last_philosopher == 1 || n == 1)//id pair, dernier philosoph ou premier vont chopper le smallest fourchette
			ft_smallest_fork(p, n, smallest_fork, x);
		else
			ft_biggest_fork(p, n, smallest_fork, x);
		}
}

void	ft_sleep_and_think(t_philo *p, int n)
{
	char *chrono_sleep;
	char *chrono_think;

	chrono_sleep = ft_itoa((int)(curr_time() - (*p).ptr->t_start));
	printf("%s %d is sleeping\n",chrono_sleep, n);
	ft_free_str(chrono_sleep);
	ft_call_usleep((*p).ptr->t_to_sleep);
	if ((*p).ptr->stop_dining_all != 1)
	{
		chrono_think = ft_itoa((int)(curr_time() - (*p).ptr->t_start));
		printf("%s %d is thinking \n",chrono_think, n);
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

	p = (t_philo *)arg;//pour eviter deadlock et famine on va ordonner les ressources et on imposera de prendre d abord la plus petite fork
	ft_call_death_check(p);
	while ((*p).ptr->stop_dining_all == 0)
	{
		n = ((*(t_philo *)arg).id);
		x = ((*(t_philo *)arg).id);
		smallest_fork = n - 1;
		if ((*(t_philo *)arg).flag_last_philosopher == 1)
		{
			smallest_fork = 0;
			x = n - 1;
		}
		else
			x = n;
		if ((*p).ptr->stop_dining_all != 1)
			ft_redirect_philosopher_to_fork(p, n, smallest_fork, x);
		if ((*p).ptr->stop_dining_all != 1)
			ft_sleep_and_think(p, n);
	}
	return (NULL);
}
