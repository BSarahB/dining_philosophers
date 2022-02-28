/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:35:37 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 06:35:41 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_struct_init_values(t_utils **ptr, char *argv[])
{
	(*ptr)->nb_of_philosophers = (int)ft_atoi(argv[1]);
	(*ptr)->t_to_sleep = (int)ft_atoi(argv[4]);
	(*ptr)->t_to_die = (int)ft_atoi(argv[2]);
	(*ptr)->t_to_eat = (int)ft_atoi(argv[3]);
	(*ptr)->t_start = 0;
	(*ptr)->nb_of_mandatory_meals = 0;
	(*ptr)->nb_of_plumpy_philos = 0;
	(*ptr)->stop_dining_all = 0;
	(*ptr)->flag_already_died = 0;
}

t_utils	*ft_struct_init(t_utils **ptr, char *argv[])
{
	*ptr = malloc(sizeof(t_utils) * 1);
	if (!(*ptr))
		return (0);
	ft_struct_init_values(ptr, argv);
	(*ptr)->th_p = NULL;
	(*ptr)->th_d = NULL;
	(*ptr)->forks = NULL;
	(*ptr)->th_p = malloc(sizeof(pthread_t) * (*ptr)->nb_of_philosophers);
	(*ptr)->th_d = malloc(sizeof(pthread_t) * (*ptr)->nb_of_philosophers);
	(*ptr)->forks = malloc(sizeof(pthread_mutex_t) * \
						(*ptr)->nb_of_philosophers);
	if ((!(*ptr)->th_p) || (!(*ptr)->th_d) || (!(*ptr)->forks))
	{
		ft_error("Error during malloc allocation\n");
		ft_free_struct_t_ptr(ptr);
		return (0);
	}
	return (*ptr);
}

int	ft_thread_generate(t_philo *philos, t_utils *ptr)
{
	if (ft_thread_create(ptr, philos, ptr->th_p, ptr->th_d))
		return (1);
	if (ft_thread_join(ptr, ptr->th_p, ptr->th_d, philos))
		return (1);
	if (ft_mutex_destroy(ptr, philos, ptr->forks, 0))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_philo	*philos;
	t_utils	*ptr;

	if (ft_check_validity(argc, argv))
		return (1);
	ptr = ft_struct_init(&ptr, argv);
	if (ft_check_malloc_ptr(ptr))
		return (1);
	philos = malloc(sizeof(t_philo) * (*ptr).nb_of_philosophers);
	if (ft_check_malloc_philos(philos, ptr))
		return (1);
	if (ft_mutex_init(ptr, ptr->forks, philos))
		return (1);
	if (ft_check_validity2(argc, argv, ptr, philos))
		return (1);
	if (ft_init_philosophers(philos, ptr))
		return (1);
	set_t_start(ptr, curr_time());
	if (ft_only_one_philo(ptr, philos))
		return (1);
	if (ft_thread_generate(philos, ptr))
		return (1);
	ft_free_struct_t_philo(&philos);
	return (0);
}
