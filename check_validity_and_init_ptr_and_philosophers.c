#include "philo.h"

int	ft_init_philosophers(t_philo *philos, t_utils *ptr)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < get_nb_of_philosophers(ptr))
	{
		k = pthread_mutex_init(&philos[i].mutex_protect, NULL);
		if (k == -1)
		{
			printf("Mutex_protect philos[i] initialization failed\n");
			ft_mutex_destroy(ptr, philos, ptr->forks, 0);
			ft_free_struct_t_ptr(&ptr);
			ft_free_struct_t_philo_only(&philos);
			return (1);
		}
		philos[i].ptr = ptr;
		set_nb_of_dinners(&philos[i],0);
		set_id(&philos[i],i+1);
		set_stop_dining_all_p(&philos[i], 0);
		if (i == (get_nb_of_philosophers(ptr) - 1))
			set_flag_last_philosopher(&philos[i],1);
		else
			set_flag_last_philosopher(&philos[i],0);
		i++;
	}
	return (0);
}

int	ft_mandatory_meals(int argc, char *argv[], t_utils *ptr)
{
	if (argc == 6)
	{
		set_nb_of_mandatory_meals(ptr,(int)ft_atoi(argv[5]));
		if (get_nb_of_mandatory_meals(ptr) <= 0)
			return (1);
	}
	else
		set_nb_of_mandatory_meals(ptr,-1);
	return (0);
}

int	ft_check_validity2(int argc, char *argv[], t_utils *ptr, t_philo *philos)
{
	if (ft_mandatory_meals(argc, argv, ptr))
	{
		ft_error("Error\n make sure your nb of meals is > 0 ");
		ft_mutex_destroy(ptr, philos, ptr->forks, 0);
		ft_free_struct_t_ptr(&ptr);
		ft_free_struct_t_philo_only(&philos);
		return (1);
	}
	if (get_nb_of_philosophers(ptr) <= 0 || get_t_to_die(ptr) <= 0 || \
	get_t_to_sleep(ptr) <= 0 || get_t_to_eat(ptr) <= 0)
	{
		ft_error("Error\n make sure your use values > 0\n");
		ft_mutex_destroy(ptr, philos, ptr->forks, 0);
		ft_free_struct_t_ptr(&ptr);
		ft_free_struct_t_philo_only(&philos);
		return (1);
	}
	return (0);
}
void	ft_init_ptr(t_utils *ptr, char *argv[], pthread_t *P,pthread_t *D, \
					pthread_mutex_t *F)
{
	set_t_to_die(ptr,(int)ft_atoi(argv[2]));
	set_t_to_eat(ptr,(int)ft_atoi(argv[3]));
	set_t_to_sleep(ptr,(int)ft_atoi(argv[4]));
	set_stop_dining_all(ptr,0);
	set_flag_already_died(ptr,0);
	(*ptr).th_p = P;
	(*ptr).forks = F;
	(*ptr).th_d = D;
}

int	ft_check_validity(int argc, char *argv[])
{
	if ((argc < 5 || argc > 6) || (ft_check_error(argv)) || \
			(ft_check_int_max(argc, argv)))
	{
		ft_error("Error\nUsage:nb_philos t_to_die to_eat t_to_sleep [meals]\n");
		return (1);
	}
	return (0);
}
