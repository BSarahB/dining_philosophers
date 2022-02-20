#include "philo.h"

int	ft_mutex_destroy(t_utils *ptr, t_philo *philos, pthread_mutex_t *F)
{
	int	p;
	int	k;

	p = 0;
	while (p < (*ptr).nb_of_philosophers)
	{
		k = pthread_mutex_destroy(&F[p]);//ret 0 si success
		if (k!=0)
		{
			printf("Mutex not Destroyed for p : %d, meal_count = %d\n", p, philos[p].nb_of_dinners);
			//TODO ft_free_struct_t_philo(&philos) / free les mallocs des threads P/ free les mallocs des mutex F / destroy les mutex / free ptr
			//Q : voir le ret si dest necessaire des mutex restant(man)
			//printf("meal_count_p1 = %d\nmeal_count_p2 = %d\nmeal_count_p3 = %d\nmeal_count p4 = %d\nmeal_count_p5 = %d\n",philos[0].nb_of_dinners,philos[1].nb_of_dinners, philos[2].nb_of_dinners, philos[3].nb_of_dinners, philos[4].nb_of_dinners);
			exit(1);
		}
		p++;
	}
	return (0);
}

int	ft_thread_join(t_utils *ptr,pthread_t *P)
{
	int	l;
	int w;

	l = 0;
	while (l < (*ptr).nb_of_philosophers)
	{//l ordre du join est irrelevant , cela force juste a attendre la fin du fil d execution de thread
		w = pthread_join(P[l], NULL);// pthread_join(P[i], &msg) //Cette fonction force le programme principal a attendre jusqu'à ce que le thread en background appelé ait fini d'exécuter sa tâche.
		if (w != 0)
		{
			//TODO ft_free_struct_t_philo(&philos) / free les mallocs des threads P/ free les mallocs des mutex F / destroy les mutex / free ptr
			//Q NANI voir sil est necessaire de exit en cas de probleme du join...
			printf("Thread join failed \n");
			exit(1);
		}
		l++;
	}
	return (0);
}

int	ft_thread_create(t_utils *ptr, t_philo *philos, pthread_t *P)
{
	int j;
	int k;

	j = 0;
	while (j < (*ptr).nb_of_philosophers)//0, 1 , 2 , 3
	{
		philos[j].last_meal_time = curr_time();//ou t_start?
		k = pthread_create(&P[j], NULL, (void *)ft_start_routine, &philos[j]);//P[0, 1, 2, 3]
		if (k != 0)
		{
			//TODO ft_free_struct_t_philo(&philos) / free les mallocs des threads P/ free les mallocs des mutex F / destroy les mutex / free ptr
			//Q : voir le ret si dest necessaire des threads crees(man)
			printf("Thread creation error \n");
			exit(1);
		}
		j++;
	}
	return (0);
}

int	ft_mutex_init(t_utils *ptr, pthread_mutex_t *F)
{
	int i;
	int k;

	i = 0;
	while (i < (*ptr).nb_of_philosophers)//0, 1, 2, 3
	{
		k = pthread_mutex_init(&F[i], NULL);//ou alors mais hors instructions 42, pthread_t_mutex F = PTHREAD_MUTEX_INITIALIZER; au lieu de pthread_mutex_init
		if (k == -1)
		{
			printf("Mutex initialization failed\n");
			//TODO ft_free_struct_t_philo(&philos) / free les mallocs des threads P/ free les mallocs des mutex F
			// detruire les mutex ayant ete initialises restant/ free ptr
			//Q Nani
			exit(1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_philo			*philos;
	pthread_t		*P;
	pthread_mutex_t	*F;
	t_utils			*ptr;

	if(ft_check_validity(argc, argv))
		return (1);//->il y a donc eu une erreur TODO sortir du programme proprement
	ptr = malloc(sizeof(t_utils) * 1);
	(*ptr).nb_of_philosophers = (int)ft_atoi(argv[1]);
	philos = malloc(sizeof(t_philo) * (*ptr).nb_of_philosophers);
	P = malloc(sizeof(pthread_t) * (*ptr).nb_of_philosophers);
	F = malloc(sizeof(pthread_mutex_t) * (*ptr).nb_of_philosophers);
	ft_init_ptr(ptr, argv, P, F);
	if(ft_check_validity2(argc, argv, ptr))
		return(1);//->il y a donc eu une erreur TODO sortir du programme proprement
	ft_init_philosophers(philos, ptr);
	(*ptr).t_start = curr_time();
	if (ft_only_one_philo(ptr, philos))
		return (1);//gerer la sortie proprement TODO ask : sortir sur 1 en cas d erreur
	ft_mutex_init(ptr, F);
	ft_thread_create(ptr, philos, P);
	ft_thread_join(ptr, P);
	ft_mutex_destroy(ptr, philos, F);
	//printf("meal_count_p1 = %d\nmeal_count_p2 = %d\nmeal_count_p3 = %d\nmeal_count p4 = %d\nmeal_count_p5 = %d\n",philos[0].nb_of_dinners,philos[1].nb_of_dinners, philos[2].nb_of_dinners, philos[3].nb_of_dinners, philos[4].nb_of_dinners);
	ft_free_struct_t_philo(&philos);
	return (0);
}
