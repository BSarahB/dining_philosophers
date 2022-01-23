#include "philo.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void	*ft_start_routine2(void *arg)
{
	pthread_mutex_lock(&mutex);

	t_philo	*p;
	int		stop;
	char *chrono_death;

	p = (t_philo *)arg;
	stop = 0;
	while (!stop)
	{
		if ((curr_time() - (*p).last_meal_time) >= (unsigned int)(*p).ptr->t_to_die)
		{
			(*p).ptr->stop_dining_all = 1;
			stop = 1;
			pthread_detach((*p).D);//pthread_detach just means that you are never going to join with the thread again.
			//This allows the pthread library to know whether it can immediately dispose of the
			//thread resources once the thread exits (the detached case) or whether
			//it must keep them around because you may later call pthread_join on the thread.
			//Once main returns (or exits) the OS will reap all your threads and destroy your process.
			chrono_death = ft_itoa((int)(curr_time() - (*p).ptr->t_start));
			printf("%s %d died\n", chrono_death, (*p).id);
			ft_free_str(chrono_death);
			//print_debug(p, "mutex of death locked after death\n");

			//pthread_mutex_lock(&mutex);


			//return (NULL);
			//->FAIRE EN SORTE QUE TOUS LES THREADS SOIENT INTERROMPUS.
			//(*p).stop_dining = 1;
			//else
		}
		else {
			stop = (*p).ptr->stop_dining_all;
		}
	}

	pthread_mutex_unlock(&mutex);
	//print_debug(p, "mutex of death unlocked\n");

	pthread_mutex_lock(&mutex);
	//print_debug(p, "mutex of death locked\n");




	return (NULL);
}


void	*ft_call_death_check(t_philo *p)
{
	int z;

	z = pthread_create(&p->D, NULL, (void *)ft_start_routine2, p);
	if (z != 0)
	{
		printf("Thread creation error \n");//perror("pthread_create failled");
		exit(1);
	}

	return (NULL);
}
