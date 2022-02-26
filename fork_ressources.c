#include "philo.h"

void	ft_call_ft_printf(t_philo *p, char c, char *chrono)
{
	if (get_stop_dining_all(p->ptr) == 1)
		return ;
	if (c == 'D')
		set_stop_dining_all(p->ptr, 1);
	if (c == 'D')
		ft_printf("%s %d DIED\n", chrono, get_id(p));
	else if (c == 'F')
		ft_printf("%s %d has taken a fork\n", chrono, get_id(p));
	else if(c == 'E')
		ft_printf("%s %d is eating\n", chrono, get_id(p));
	else if (c == 'S')
		ft_printf("%s %d is sleeping\n",chrono, get_id(p));
	else if(c == 'T')
		ft_printf("%s %d is thinking\n",chrono, get_id(p));

}

void	ft_biggest_fork(t_philo *p, int smallest_fork, int big_fork)
{
	char *chrono_bfork;
	char *chrono_sfork;
	char *chrono_eat;
	pthread_mutex_t *F;

	F = (*p).ptr->F;
	pthread_mutex_lock(&F[big_fork]);
	chrono_bfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'F', chrono_bfork);
	ft_free_str(chrono_bfork);
	pthread_mutex_lock(&F[smallest_fork]);
	chrono_sfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	chrono_eat = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'F', chrono_sfork);
	ft_call_ft_printf(p, 'E', chrono_eat);
	set_nb_of_dinners(p,get_nb_of_dinners(p) + 1);
	set_last_meal_time(p,curr_time());
	ft_call_usleep(get_t_to_eat(p->ptr));
	ft_free_str(chrono_sfork);
	ft_free_str(chrono_eat);
	pthread_mutex_unlock(&F[big_fork]);
	pthread_mutex_unlock(&F[smallest_fork]);
	ft_printf("P%d a repose les fourchettes\n", get_id(p));
}

void	ft_smallest_fork(t_philo *p, int smallest_fork, int big_fork)
{
	char *chrono_bfork;
	char *chrono_sfork;
	char *chrono_eat;
	pthread_mutex_t *F;

	F = (*p).ptr->F;
	pthread_mutex_lock(&F[smallest_fork]);
	chrono_sfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'F', chrono_sfork);
	ft_free_str(chrono_sfork);
	pthread_mutex_lock(&F[big_fork]);
	chrono_bfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	chrono_eat = ft_itoa((int)(curr_time() - get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'F', chrono_bfork);
	ft_call_ft_printf(p, 'E', chrono_eat);
	set_nb_of_dinners(p,get_nb_of_dinners(p) + 1);
	set_last_meal_time(p,curr_time());
	ft_call_usleep(get_t_to_eat(p->ptr));
	ft_free_str(chrono_bfork);
	ft_free_str(chrono_eat);
	pthread_mutex_unlock(&F[smallest_fork]);
	pthread_mutex_unlock(&F[big_fork]);
	ft_printf("P%d a repose les fourchettes\n", get_id(p));
}
