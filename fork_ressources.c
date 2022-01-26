#include "philo.h"

void	ft_biggest_fork(t_philo *p, int n, int smallest_fork, int x)
{
	char *chrono_bfork;
	char *chrono_sfork;
	char *chrono_eat;
	pthread_mutex_t *F;

	F = (*p).ptr->F;
	pthread_mutex_lock(&F[x]);
	if((*p).ptr->stop_dining_all == 1)
	{
			pthread_mutex_unlock(&F[x]);
			return;
}
	chrono_bfork = ft_itoa((int)(curr_time()- (*p).ptr->t_start));
	printf("%s %d has taken a fork : %d\n", chrono_bfork, n, x);
	fflush(stdout);
	ft_free_str(chrono_bfork);
	pthread_mutex_lock(&F[smallest_fork]);
	if((*p).ptr->stop_dining_all == 1)
	{
			pthread_mutex_unlock(&F[smallest_fork]);
			return;
}

	chrono_sfork = ft_itoa((int)(curr_time()- (*p).ptr->t_start));
	printf("%s %d has taken a fork :  %d\n",chrono_sfork, n, smallest_fork);
	ft_free_str(chrono_sfork);
	chrono_eat = ft_itoa((int)(curr_time()- (*p).ptr->t_start));
	printf("%s %d is eating\n", chrono_eat, n);
	ft_free_str(chrono_eat);
	fflush(stdout);
	(*p).last_meal_time = curr_time();
	(*p).nb_of_dinners++;
	ft_call_usleep((*p).ptr->t_to_eat);
	pthread_mutex_unlock(&F[x]);
	pthread_mutex_unlock(&F[smallest_fork]);

}

void	ft_smallest_fork(t_philo *p, int n, int smallest_fork, int x)
{
	char *chrono_bfork;
	char *chrono_sfork;
	char *chrono_eat;
	pthread_mutex_t *F;

	F = (*p).ptr->F;
	pthread_mutex_lock(&F[smallest_fork]);

	if((*p).ptr->stop_dining_all == 1)
	{
			pthread_mutex_unlock(&F[smallest_fork]);
			return;
}
	chrono_sfork = ft_itoa((int)(curr_time()- (*p).ptr->t_start));

	printf("%s %d has taken a fork :  %d\n",chrono_sfork, n, smallest_fork);
	ft_free_str(chrono_sfork);
	fflush(stdout);
	pthread_mutex_lock(&F[x]);

			if((*p).ptr->stop_dining_all == 1)
			{
					pthread_mutex_unlock(&F[x]);
					return;
		}
	chrono_bfork = ft_itoa((int)(curr_time()- (*p).ptr->t_start));
	printf("%s %d has taken a fork : %d\n",chrono_bfork, n, x);	// == printf("%d has taken the biggest fork : %d\n", n, x);
	ft_free_str(chrono_bfork);
	chrono_eat = ft_itoa((int)(curr_time() - (*p).ptr->t_start));
	printf("%s %d is eating\n",chrono_eat,n);
	ft_free_str(chrono_eat);
	fflush(stdout);
	(*p).last_meal_time = curr_time();
	(*p).nb_of_dinners++;
	ft_call_usleep((*p).ptr->t_to_eat);
	pthread_mutex_unlock(&F[smallest_fork]);//la plus petite
	pthread_mutex_unlock(&F[x]);//la fourchette la plus grande

}
