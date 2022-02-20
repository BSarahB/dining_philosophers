#include "philo.h"

void	ft_init_philosophers(t_philo *philos, t_utils *ptr)
{
	int i;

	i = 0;
	while (i < (*ptr).nb_of_philosophers)
	{
		philos[i].ptr = ptr;
		philos[i].nb_of_dinners = 0;
		philos[i].id = i + 1;
		if (i == ((*ptr).nb_of_philosophers - 1))
			philos[i].flag_last_philosopher = 1;
		else{
			philos[i].flag_last_philosopher = 0;
		}
		i++;
	}
}

int	ft_mandatory_meals(int argc, char *argv[], t_utils *ptr)
{
	if (argc == 6)
	{
		(*ptr).nb_of_mandatory_meals = (int)ft_atoi(argv[5]);
		if ((*ptr).nb_of_mandatory_meals <= 0)
			return (1);//cf sil mettre un msg d erreur ou pas //TODO
	}
	else
		(*ptr).nb_of_mandatory_meals = -1;
	return (0);
}

int	ft_check_validity2(int argc, char *argv[], t_utils *ptr)
{
	if (ft_mandatory_meals(argc, argv, ptr))
	{
		//TODO ft_free_struct_t_philo(&philos) / free les threads P/ free les mutex F / free ptr
		//msg d erreur
		return (1);// gerer le return et sortir proprement TODO
	}
	if ((*ptr).nb_of_philosophers <= 0 || (*ptr).t_to_die <= 0 || \
		(*ptr).t_to_sleep <= 0 || (*ptr).t_to_eat <= 0)
	{
		//TODO ft_free_struct_t_philo(&philos) / free les mallocs des threads P/ free les mallocs des mutex F / free ptr
		//msg d erreur
		return (1);////cf sil mettre un msg d erreur ou pas
	}
	return (0);
}
void	ft_init_ptr(t_utils *ptr, char *argv[], pthread_t *P, pthread_mutex_t *F)
{
	(*ptr).t_to_die = (int)ft_atoi(argv[2]);
	(*ptr).t_to_eat = (int)ft_atoi(argv[3]);
	(*ptr).t_to_sleep = (int)ft_atoi(argv[4]);
	(*ptr).stop_dining_all = 0;
	(*ptr).P = P;
	(*ptr).F = F;
}

int	ft_check_validity(int argc, char *argv[])
{
	if ((argc < 5 || argc > 6) || (ft_check_error(argv)) || (ft_check_int_max(argc, argv)))
	{
		//TODO ft_free_struct_t_philo(&philos) / free les mallocs threads P/ free les mallocs mutex F / free ptr
		//msg d erreur
		ft_error("Error\nUsage: nb_philos time_to_die time_to_eat time_to_sleep [nb_mandatory_meals]\n");
		return (1);//TODO
	}
	return (0);
}
