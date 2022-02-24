#include "philo.h"

int	ft_mutex_destroy(t_utils *ptr, t_philo *philos, pthread_mutex_t *F, int p)
{
	int k;

    while (p < get_nb_of_philosophers(ptr))
	{
		k = pthread_mutex_destroy(&F[p]);
		if (k!=0)
		{
            ft_printf("Mutex not Destroyed for p : %d, meal_count = %d\n",get_id(&philos[p]), get_nb_of_dinners(&philos[p]));
			ft_mutex_destroy(ptr, philos, F, p + 1);
			ft_free_struct_t_philo(&philos);
			exit(1);
		}
		p++;
	}
	pthread_mutex_destroy(&ptr->mutex);
	pthread_mutex_destroy(&ptr->mutex666);
	pthread_mutex_destroy(&ptr->mutex_debug_msg666);
	pthread_mutex_destroy(&ptr->mutex_debug_msg);
	pthread_mutex_destroy(&ptr->mutex_msg);
	return (0);
}

int	ft_thread_join(t_utils *ptr, pthread_t *P,  pthread_t *D, t_philo *philos)
{
	int	l;
	int w;
	int ww;

	l = 0;
    while (l < get_nb_of_philosophers(ptr))
	{
		w = pthread_join(P[l], NULL);
		if (w != 0)
		{
            ft_printf("Thread P join failed \n");
		}
		ww = pthread_join(D[l], NULL);
		if (ww != 0 )
		{
            ft_printf("Thread D join failed \n");
		}
		if (w || ww)
		{
			ft_free_struct_t_philo(&philos);
			ft_mutex_destroy(ptr, philos, (*ptr).F, 0);
			exit(1);
		}

		l++;
	}
	return (0);
}

int	ft_thread_create(t_utils *ptr, t_philo *philos, pthread_t *P, pthread_t *D)
{
	int j;
	int k;

	j = 0;
    while (j < get_nb_of_philosophers(ptr))
	{
        set_last_meal_time(&philos[j],curr_time());
		k = pthread_create(&P[j], NULL, (void *)ft_start_routine, &philos[j]);
		if (k != 0)
		{
            ft_printf("Thread creation error \n");
			ft_free_struct_t_philo(&philos);
			ft_mutex_destroy(ptr, philos, (*ptr).F, 0);
			exit(1);
		}
		k = pthread_create(&D[j], NULL, (void *)ft_start_routine666, &philos[j]);
		if (k != 0)
		{
            ft_printf("Thread creation error \n");
			ft_free_struct_t_philo(&philos);
			ft_mutex_destroy(ptr, philos, (*ptr).F, 0);
			exit(1);
		}
		j++;
	}
	return (0);
}

int	ft_mutex_init(t_utils *ptr, pthread_mutex_t *F, t_philo *philos)
{
	int i;
	int k;

	i = 0;
    while (i < get_nb_of_philosophers(ptr))
	{
		k = pthread_mutex_init(&F[i], NULL);
		if (k == -1)
		{
            ft_printf("Mutex initialization failed\n");
			ft_free_struct_t_philo(&philos);
			exit(1);
		}
		i++;
	}
	pthread_mutex_init(&ptr->mutex, NULL);
	pthread_mutex_init(&ptr->mutex666, NULL);
	pthread_mutex_init(&ptr->mutex_debug_msg666, NULL);
	pthread_mutex_init(&ptr->mutex_debug_msg, NULL);
	pthread_mutex_init(&ptr->mutex_msg, NULL);
	return (0);
}

void ft_printf(const char * format, ...)
{
#ifdef PRINT_DEBUG
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
    fflush(stdout);
#endif
}

int main(int argc, char *argv[])
{
	t_philo			*philos;
	pthread_t		*P;
	pthread_t		*D;

	pthread_mutex_t	*F;
	t_utils			*ptr;
	if(ft_check_validity(argc, argv))
		return (1);
	ptr = malloc(sizeof(t_utils) * 1);
    set_nb_of_philosophers(ptr,(int)ft_atoi(argv[1]));
    philos = malloc(sizeof(t_philo) * get_nb_of_philosophers(ptr));
    P = malloc(sizeof(pthread_t) * get_nb_of_philosophers(ptr));
    D = malloc(sizeof(pthread_t) * get_nb_of_philosophers(ptr));

    F = malloc(sizeof(pthread_mutex_t) * get_nb_of_philosophers(ptr));
	ft_init_ptr(ptr, argv, P,D, F);
	if(ft_check_validity2(argc, argv, ptr, philos))
		return(1);
	ft_init_philosophers(philos, ptr);
    set_t_start(ptr,curr_time());
	if (ft_only_one_philo(ptr, philos))
		return (1);
	if (ft_mutex_init(ptr, F, philos))
		return (1);
	if (ft_thread_create(ptr, philos, P, D))
		return (1);
	if (ft_thread_join(ptr, P, D, philos))
		return(1);
	if (ft_mutex_destroy(ptr, philos, F, 0))
		return(1);
	ft_free_struct_t_philo(&philos);
	return (0);
}
