#include "philo.h"

void	ft_biggest_fork(t_philo *p, int n, int smallest_fork, int x)
{
	char *chrono_bfork;
	char *chrono_sfork;
	char *chrono_eat;
	pthread_mutex_t *F;

	F = (*p).ptr->F;
	pthread_mutex_lock(&F[x]);
    if(get_stop_dining_all(p->ptr) == 1)
	{
			pthread_mutex_unlock(&F[x]);
			return;
	}
    chrono_bfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
    ft_printf("%s %d has taken a fork\n", chrono_bfork, n);
	ft_free_str(chrono_bfork);
	pthread_mutex_lock(&F[smallest_fork]);
    if(get_stop_dining_all(p->ptr) == 1)
	{
			pthread_mutex_unlock(&F[smallest_fork]);
			pthread_mutex_unlock(&F[x]);
			return;
	}
    chrono_sfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
    chrono_eat = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
    set_last_meal_time(p,curr_time());
    set_nb_of_dinners(p,get_nb_of_dinners(p)+1);
    ft_printf("%s %d has taken a fork\n",chrono_sfork, n);
    ft_printf("%s %d is eating\n", chrono_eat, n);
    if (get_nb_of_mandatory_meals(p->ptr) != -1 && get_nb_of_dinners(p) == get_nb_of_mandatory_meals(p->ptr))
	{
        ft_printf("dans la check mandatory meals avec p: %d - avec nb_of_dinners: %d\n", get_id(p), get_nb_of_dinners(p));
        set_nb_of_plumpy_philos(p->ptr,get_nb_of_plumpy_philos(p->ptr)+1);
        if (get_nb_of_plumpy_philos(p->ptr) == get_nb_of_philosophers(p->ptr))
            set_stop_dining_all(p->ptr,1);
		ft_free_str(chrono_sfork);
		ft_free_str(chrono_eat);
		pthread_mutex_unlock(&F[x]);
		pthread_mutex_unlock(&F[smallest_fork]);
		return;
	}
    ft_call_usleep(get_t_to_eat(p->ptr));
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
    if(get_stop_dining_all(p->ptr) == 1)
	{
			pthread_mutex_unlock(&F[smallest_fork]);
			return;
	}
    chrono_sfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
    ft_printf("%s %d has taken a fork\n",chrono_sfork, n);
	ft_free_str(chrono_sfork);
	pthread_mutex_lock(&F[x]);
    if(get_stop_dining_all(p->ptr) == 1)
	{
			pthread_mutex_unlock(&F[x]);
			pthread_mutex_unlock(&F[smallest_fork]);

				return;
	}
    chrono_bfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
    chrono_eat = ft_itoa((int)(curr_time() - get_t_start(p->ptr)));
    set_last_meal_time(p,curr_time());
    set_nb_of_dinners(p,get_nb_of_dinners(p)+1);
    ft_printf("%s %d has taken a fork\n",chrono_bfork, n);	// == ft_printf("%d has taken the biggest fork : %d\n", n, x);
    ft_printf("%s %d is eating\n",chrono_eat,n);
    if (get_nb_of_mandatory_meals(p->ptr) != -1 && get_nb_of_dinners(p) == get_nb_of_mandatory_meals(p->ptr))
	{
        ft_printf("dans la check mandatory meals avec p: %d - avec nb_of_dinners: %d\n", get_id(p), get_nb_of_dinners(p));
        set_nb_of_plumpy_philos(p->ptr,get_nb_of_plumpy_philos(p->ptr)+1);
        if (get_nb_of_plumpy_philos(p->ptr) == get_nb_of_philosophers(p->ptr))
            set_stop_dining_all(p->ptr,1);
		ft_free_str(chrono_bfork);
		ft_free_str(chrono_eat);
		pthread_mutex_unlock(&F[smallest_fork]);//la plus petite
		pthread_mutex_unlock(&F[x]);//la fourchette la plus grande
		return;
	}
    ft_call_usleep(get_t_to_eat(p->ptr));
	ft_free_str(chrono_bfork);
	ft_free_str(chrono_eat);
	pthread_mutex_unlock(&F[smallest_fork]);//la plus petite
	pthread_mutex_unlock(&F[x]);//la fourchette la plus grande
}
