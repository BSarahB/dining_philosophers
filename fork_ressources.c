#include "philo.h"

void	ft_biggest_fork(t_philo *p, int n, int smallest_fork, int x)
{

	pthread_mutex_lock(&F[x]);
	if((*p).ptr->stop_dining_all == 1)
	{
			pthread_mutex_unlock(&F[x]);
			return;
}
	printf("%s %d has taken a fork : %d\n", ft_itoa((int)(curr_time() - (*p).ptr->t_start)), n, x);

	pthread_mutex_lock(&F[smallest_fork]);
	if((*p).ptr->stop_dining_all == 1)
	{
			pthread_mutex_unlock(&F[smallest_fork]);
			return;
}

	printf("%s %d has taken a fork :  %d\n",ft_itoa((int)(curr_time() - (*p).ptr->t_start)), n, smallest_fork);
	printf("%s %d is eating\n", ft_itoa((int)(curr_time() - (*p).ptr->t_start)),n);
	(*p).last_meal_time = curr_time();
	(*p).nb_of_dinners++;
	//usleep(9000 * 1000);

	ft_call_usleep((*p).ptr->t_to_eat);

	pthread_mutex_unlock(&F[x]);
	pthread_mutex_unlock(&F[smallest_fork]);

}

void	ft_smallest_fork(t_philo *p, int n, int smallest_fork, int x)
{

	pthread_mutex_lock(&F[smallest_fork]);
	if((*p).ptr->stop_dining_all == 1)
	{
			pthread_mutex_unlock(&F[smallest_fork]);
			return;
}

	printf("%s %d has taken a fork :  %d\n",ft_itoa((int)(curr_time() - (*p).ptr->t_start)), n, smallest_fork);
	fflush(stdout);

	pthread_mutex_lock(&F[x]);
			if((*p).ptr->stop_dining_all == 1)
			{
					pthread_mutex_unlock(&F[x]);
					return;
		}
	printf("%s %d has taken a fork : %d\n",ft_itoa((int)(curr_time() - (*p).ptr->t_start)), n, x);	// == printf("%d has taken the biggest fork : %d\n", n, x);
	printf("%s %d is eating\n", ft_itoa((int)(curr_time() - (*p).ptr->t_start)),n);
	fflush(stdout);
	(*p).last_meal_time = curr_time();
	(*p).nb_of_dinners++;
	//usleep(9000 * 1000);

	ft_call_usleep((*p).ptr->t_to_eat);

	pthread_mutex_unlock(&F[smallest_fork]);//la plus petite
	pthread_mutex_unlock(&F[x]);//la fourchette la plus grande

}
