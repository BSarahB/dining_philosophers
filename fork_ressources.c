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
	chrono_eat = ft_itoa((int)(curr_time()- (*p).ptr->t_start));
	(*p).last_meal_time = curr_time();
	(*p).nb_of_dinners++;
	printf("%s %d has taken a fork :  %d\n",chrono_sfork, n, smallest_fork);

	printf("%s %d is eating\n", chrono_eat, n);
	fflush(stdout);
	if ((*p).ptr->nb_of_mandatory_meals != -1 && (*p).nb_of_dinners == (*p).ptr->nb_of_mandatory_meals)
	{
		printf("dans la check mandatory meals avec p: %d - avec nb_of_dinners: %d\n", (*p).id, (*p).nb_of_dinners);
		//lock? et unlock necessaire ou pas?
		(*p).ptr->nb_of_plumpy_philos++;
		if ((*p).ptr->nb_of_plumpy_philos == (*p).ptr->nb_of_philosophers)
			(*p).ptr->stop_dining_all = 1;
	//	ft_call_usleep((*p).ptr->t_to_eat);


		ft_free_str(chrono_sfork);
		ft_free_str(chrono_eat);

		pthread_mutex_unlock(&F[x]);
		pthread_mutex_unlock(&F[smallest_fork]);
		return;
	}
	ft_call_usleep((*p).ptr->t_to_eat);
	ft_free_str(chrono_sfork);
	ft_free_str(chrono_eat);

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
	chrono_eat = ft_itoa((int)(curr_time() - (*p).ptr->t_start));
	(*p).last_meal_time = curr_time();
	(*p).nb_of_dinners++;
	printf("%s %d has taken a fork : %d\n",chrono_bfork, n, x);	// == printf("%d has taken the biggest fork : %d\n", n, x);
	printf("%s %d is eating\n",chrono_eat,n);

	fflush(stdout);
	if ((*p).ptr->nb_of_mandatory_meals != -1 && (*p).nb_of_dinners == (*p).ptr->nb_of_mandatory_meals)
	{
		printf("dans la check mandatory meals avec p: %d - avec nb_of_dinners: %d\n", (*p).id, (*p).nb_of_dinners);
		//lock? et unlock necessaire ou pas?
		(*p).ptr->nb_of_plumpy_philos++;
		if ((*p).ptr->nb_of_plumpy_philos == (*p).ptr->nb_of_philosophers)
			(*p).ptr->stop_dining_all = 1;
		ft_free_str(chrono_bfork);
		ft_free_str(chrono_eat);
		pthread_mutex_unlock(&F[smallest_fork]);//la plus petite
		pthread_mutex_unlock(&F[x]);//la fourchette la plus grande
		return;
	}
	ft_call_usleep((*p).ptr->t_to_eat);
	ft_free_str(chrono_bfork);
	ft_free_str(chrono_eat);
	pthread_mutex_unlock(&F[smallest_fork]);//la plus petite
	pthread_mutex_unlock(&F[x]);//la fourchette la plus grande

}
