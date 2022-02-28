#include "philo.h"

int	ft_mutex_destroy(t_utils *ptr, t_philo *philos, pthread_mutex_t *F, int p)
{
	int	k;
	int	kk;

	while (p < get_nb_of_philosophers(ptr))//p++
	{
		k = pthread_mutex_destroy(&F[p]);
		if (k != 0)
			printf("Mutex F not Destroyed for %d\n",get_id(&philos[p]));
		kk = pthread_mutex_destroy(&philos[p].mutex_protect);
		if (kk != 0 )
			printf("Mutex_protect not Destroyed for %d\n",get_id(&philos[p]));
		if (k != 0 || kk != 0)
		{
			ft_mutex_destroy(ptr, philos, F, p + 1);
			ft_free_struct_t_philo(&philos);
			return(1);
		}
		p++;
	}
	pthread_mutex_destroy(&ptr->mutex666);
	pthread_mutex_destroy(&ptr->mutex_printf);
	pthread_mutex_destroy(&ptr->mutex_protect);
	return (0);
}

int	ft_thread_join(t_utils *ptr, pthread_t *P,  pthread_t *D, t_philo *philos)
{
	int	l;
	int w;
	int ww;

	l = 0;
	while (l < get_nb_of_philosophers(ptr))//l++
	{
		w = pthread_join(P[l], NULL);
		if (w != 0)
			printf("Thread P join failed \n");
		ww = pthread_join(D[l], NULL);
		if (ww != 0 )
			printf("Thread D join failed \n");
		if (w || ww)
		{
			ft_mutex_destroy(ptr, philos, (*ptr).F, 0);
			ft_free_struct_t_philo(&philos);
			return(1);
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
	while (j < get_nb_of_philosophers(ptr))//j++
	{
		set_last_meal_time(&philos[j],curr_time());
		k = pthread_create(&P[j], NULL, (void *)ft_start_routine, &philos[j]);
		if (k != 0)
		{
			ft_error("Thread creation error \n");
			ft_mutex_destroy(ptr, philos, (*ptr).F, 0);
			ft_free_struct_t_philo(&philos);
			return (1);
		}
		k = pthread_create(&D[j], NULL, (void *)ft_start_routine666, &philos[j]);
		if (k != 0)
		{
			printf("Thread creation error \n");
			ft_mutex_destroy(ptr, philos, (*ptr).F, 0);
			ft_free_struct_t_philo(&philos);
			return (1);
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
	k = pthread_mutex_init(&ptr->mutex666, NULL);
	if (k == -1)
		ft_error("Mutex_666 initialization failed\n");
	k = pthread_mutex_init(&ptr->mutex_printf, NULL);
	if (k == -1)
		ft_error("Mutex_printf initialization failed\n");
	k = pthread_mutex_init(&ptr->mutex_protect, NULL);
	if (k == -1)
		ft_error("Mutex_protect of ptr initialization failed\n");

	while (i < get_nb_of_philosophers(ptr))
	{
		k = pthread_mutex_init(&F[i], NULL);
		if (k == -1)
			ft_error("Mutex F initialization failed\n");
		i++;
	}
	if (k == -1)
	{
		ft_free_struct_t_ptr(&ptr);
		ft_free_struct_t_philo_only(&philos);
		return(1);
	}
	return (0);
}


t_utils	*ft_struct_init(t_utils **ptr, char *argv[])
{
	*ptr = malloc(sizeof(t_utils) * 1);
	if (!(*ptr))
		return (0);
	(*ptr)->nb_of_philosophers = (int)ft_atoi(argv[1]);
	(*ptr)->t_to_sleep = (int)ft_atoi(argv[4]);
	(*ptr)->t_to_die = (int)ft_atoi(argv[2]);
	(*ptr)->t_to_eat = (int)ft_atoi(argv[3]);
	(*ptr)->t_start= 0;
	(*ptr)->nb_of_mandatory_meals = 0;
	(*ptr)->nb_of_plumpy_philos = 0;
	(*ptr)->stop_dining_all = 0;
	(*ptr)->flag_already_died = 0;
	(*ptr)->P = NULL;
	(*ptr)->D = NULL;
	(*ptr)->F = NULL;
	(*ptr)->P = malloc(sizeof(pthread_t) * (*ptr)->nb_of_philosophers);
	(*ptr)->D = malloc(sizeof(pthread_t) * (*ptr)->nb_of_philosophers);
	(*ptr)->F = malloc(sizeof(pthread_mutex_t) * (*ptr)->nb_of_philosophers);
	if ((!(*ptr)->P) || (!(*ptr)->D) || (!(*ptr)->F))
	{
		ft_error("Error during malloc allocation\n");
		ft_free_struct_t_ptr(ptr);
		return (0);
	}
	return (*ptr);
}

int	ft_check_malloc_ptr(t_utils *ptr)
{
	if(!ptr)
	{
		ft_error("Error during ptr malloc allocation\n");
		return (1);
	}
	return (0);
}

int	ft_check_malloc_philos(t_philo *philos, t_utils *ptr)
{
	if(!philos)
	{
		ft_error("Error during ptr malloc allocation\n");
		ft_free_struct_t_ptr(&ptr);
		return (1);
	}
	return (0);
}

int	ft_thread_generate(t_philo *philos, t_utils *ptr)
{
	if (ft_thread_create(ptr, philos, ptr->P, ptr->D))
		return (1);
	if (ft_thread_join(ptr, ptr->P, ptr->D, philos))
		return (1);
	return (0);

}

int main(int argc, char *argv[])
{
	t_philo			*philos;
	t_utils			*ptr;

	if(ft_check_validity(argc, argv))
		return (1);
	ptr = ft_struct_init(&ptr, argv);
	if (ft_check_malloc_ptr(ptr))
		return (1);
	philos = malloc(sizeof(t_philo) * (*ptr).nb_of_philosophers);
	if (ft_check_malloc_philos(philos, ptr))
		return (1);
	if (ft_mutex_init(ptr, ptr->F, philos))
		return (1);
	if(ft_check_validity2(argc, argv, ptr, philos))
		return(1);
	if (ft_init_philosophers(philos, ptr))
		return (1);
	set_t_start(ptr,curr_time());
	if (ft_only_one_philo(ptr, philos))
		return (1);
	if(ft_thread_generate(philos, ptr))
		return (1);
	if (ft_mutex_destroy(ptr, philos, ptr->F, 0))
		return(1);
	ft_free_struct_t_philo(&philos);
	return (0);
}
