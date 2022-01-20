#include "philo.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void	*ft_start_routine2(void *arg)
{
	pthread_mutex_lock(&mutex);

	t_philo	*p;
	int		stop;

	p = (t_philo *)arg;
	stop = 0;
	while (!stop)
	{
		if ((curr_time() - (*p).last_meal_time) >= (unsigned int)(*p).ptr->t_to_die)
		{
			printf("%s %d died\n", ft_itoa((int)(curr_time() - (*p).ptr->t_start)), (*p).id);
			stop = 1;
			(*p).ptr->stop_dining_all = 1;
			pthread_mutex_unlock(&mutex);

			return (NULL);
			//->FAIRE EN SORTE QUE TOUS LES THREADS SOIENT INTERROMPUS.
			//(*p).stop_dining = 1;
			//else
		//stop = p->info->stop + p->stop;
		}
		else {
			stop = (*p).ptr->stop_dining_all;
		}
	}
	pthread_mutex_unlock(&mutex);


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
	//if (pthread_create(&p->faucheuse, NULL, &is_dead, p))//on lance le processus leger faucheuse
	//pthread_detach(p->D);
	return (NULL);
}
