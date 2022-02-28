/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 04:19:23 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 04:19:40 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_biggest_fork(t_philo *p, int smallest_fork, int big_fork)
{
	char *chrono_bfork;
	char *chrono_sfork;
	char *chrono_eat;
	pthread_mutex_t *F;

	F = (*p).ptr->forks;
	pthread_mutex_lock(&F[big_fork]);
	chrono_bfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'F', chrono_bfork);
	ft_free_str(chrono_bfork);
	pthread_mutex_lock(&F[smallest_fork]);
	pthread_mutex_lock(&(*p).ptr->mutex666);
	set_last_meal_time(p,curr_time());
	pthread_mutex_unlock(&(*p).ptr->mutex666);
	chrono_sfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	chrono_eat = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'F', chrono_sfork);
	ft_call_ft_printf(p, 'E', chrono_eat);
	set_nb_of_dinners(p,get_nb_of_dinners(p) + 1);
	ft_call_usleep(get_t_to_eat(p->ptr));
	ft_free_str(chrono_sfork);
	ft_free_str(chrono_eat);
	pthread_mutex_unlock(&F[big_fork]);
	pthread_mutex_unlock(&F[smallest_fork]);
}

void	ft_smallest_fork(t_philo *p, int smallest_fork, int big_fork)
{
	char *chrono_bfork;
	char *chrono_sfork;
	char *chrono_eat;
	pthread_mutex_t *F;

	F = (*p).ptr->forks;
	pthread_mutex_lock(&F[smallest_fork]);
	chrono_sfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'F', chrono_sfork);
	ft_free_str(chrono_sfork);
	pthread_mutex_lock(&F[big_fork]);
	pthread_mutex_lock(&(*p).ptr->mutex666);
	set_last_meal_time(p,curr_time());
	pthread_mutex_unlock(&(*p).ptr->mutex666);
	chrono_bfork = ft_itoa((int)(curr_time()- get_t_start(p->ptr)));
	chrono_eat = ft_itoa((int)(curr_time() - get_t_start(p->ptr)));
	ft_call_ft_printf(p, 'F', chrono_bfork);
	ft_call_ft_printf(p, 'E', chrono_eat);
	set_nb_of_dinners(p,get_nb_of_dinners(p) + 1);
	ft_call_usleep(get_t_to_eat(p->ptr));
	ft_free_str(chrono_bfork);
	ft_free_str(chrono_eat);
	pthread_mutex_unlock(&F[smallest_fork]);
	pthread_mutex_unlock(&F[big_fork]);
}
