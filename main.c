﻿/*BUGG NANI
 * gdb -tui a.out 2
 * (gdb) r 2
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program:[ No Source Available ] 2
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
[New Thread 0x7ffff7da0700 (LWP 19179)]
flag_last_philo : 0
ca va
x : 1
Philosopher 1 has taken the smallest fork :  0
PhilosopherThread 0x7ffff7da17 In: __GI___pthread_tim* L84   PC: 0x7ffff7f99657
Thread 1 "a.out" received signal SIGINT, Interrupt.
0x00007ffff7f99657 in __GI___pthread_timedjoin_ex (threadid=140737209038592,
	thread_return=0x0, abstime=<optimized out>, block=<optimized out>)
	at pthread_join_common.c:84
(gdb) pthread_join_common.c:1: No such file or directory.
(gdb) pthread_join_common.c:1: No such file or directory.
(gdb) pthread_join_common.c:1: No such file or directory.
(gdb)
*/




/*mutex (mutual exclusion)
Primitive de synchronisation permettant d'empêcher que deux threads accèdent simultanément à une même section critique.
pr mettre en place les sections critiques, on peut utiliser le systeme, il propose des variables partagees qui peuvent etre testees et modifiees de maniere unitaire : les verruos ou mutex
en tant que primitive de synchronisation elle  permet : de verifier qu on est autorise a passer, d interdire le passage aux autres. 
les 2 actions sont faites en une seule instruction atomique et pas avec une while et une assignation de la variable testee (ceci etant fait en 2 temps)
sémaphore
Primitive de synchronisation permettant notamment l'exclusion mutuelle. Voir notamment [Downey2008]

Program name
Turn in files
Makefile
Arguments
External functs.
Libft authorized
Description
philo
philo/
Yes
[number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
No
philosopher with threads and mutex

timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died


*/
//METHODOLOGIE : on a un probleme car l ordre d execution des processus vient impacter le resultat. On doit donc synchroniser les processus(ici legers),
//pour cela on doit identifier quelle est la section critique et locker cette section critique
//une section critique arrive qd on a de la data partagee entre plsueirus processus ou threads -> une variable par ex, et donc proteger l acces a la variable en question
//le pthread_mutex est un verrou qui va garantir l exclusion  mutuelle
//avant d utiliser la ressource paratgee , la variable ou le morceau de code, on lock le mutex , et apres avoir utilise la variable on unlock le mutex
//1 seul thread a la fois pourra acceder la section critique ,

#include "philo.h"


pthread_t P[5];
pthread_mutex_t F[5];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void	ft_biggest_fork(t_philo *p, int n, int smallest_fork, int x)
{
	pthread_mutex_lock(&F[x]);
	printf("%s %d has taken a fork : %d\n", ft_itoa((int)(get_time() - (*p).ptr->t_start)), n, x);

	pthread_mutex_lock(&F[smallest_fork]);
	printf("%s %d has taken a fork :  %d\n",ft_itoa((int)(get_time() - (*p).ptr->t_start)), n, smallest_fork);
	printf("%s %d is eating\n", ft_itoa((int)(get_time() - (*p).ptr->t_start)),n);
	(*p).nb_of_dinners++;
	ft_usleep((*p).ptr->t_to_eat);
	pthread_mutex_unlock(&F[x]);
	pthread_mutex_unlock(&F[smallest_fork]);
}


void	ft_smallest_fork(t_philo *p, int n, int smallest_fork, int x)
{
	pthread_mutex_lock(&F[smallest_fork]);
	printf("%s %d has taken a fork :  %d\n",ft_itoa((int)(get_time() - (*p).ptr->t_start)), n, smallest_fork);
	fflush(stdout);
	pthread_mutex_lock(&F[x]);
	printf("%s %d has taken a fork : %d\n",ft_itoa((int)(get_time() - (*p).ptr->t_start)), n, x);	// == printf("%d has taken the biggest fork : %d\n", n, x);
	printf("%s %d is eating\n", ft_itoa((int)(get_time() - (*p).ptr->t_start)),n);
	fflush(stdout);
	(*p).nb_of_dinners++;
	ft_usleep((*p).ptr->t_to_eat);
	pthread_mutex_unlock(&F[smallest_fork]);//la plus petite
	pthread_mutex_unlock(&F[x]);//la fourchette la plus grande
}

void *ft_start_routine(void *arg)
{

	int stop_dining;
//pour eviter deadlock et famine on va ordonner les ressources et on imposera de prendre d abord la plus petite fork
	stop_dining = 0;
	while (stop_dining == 0)
	{

	//pthread_mutex_lock(&mutex);

	int n;
	int x;
	int smallest_fork;

	/* //1 ere possibilite de cast
	n = (long)arg;
	*/
	//2 eme possibilite de cast:
	t_philo	*p;


	p = (t_philo *)arg;
	n = ((*(t_philo *)arg).id); //cqfd TODO
	x = ((*(t_philo *)arg).id);
int flag = (*(t_philo *)arg).flag_last_philosopher;




smallest_fork = n - 1;
if (flag == 1)
{

	if (x % 2 != 0)
		x = n - 1;
	smallest_fork = (x % 2);//pour le last_philosopher

}
else
	x = n;




if (n % 2 != 0)
	ft_smallest_fork(p, n, smallest_fork, x);
else
	ft_biggest_fork(p, n, smallest_fork, x);


	//n = (*(int *)arg); //cqfd TODO


	//TODO verifier les index des P et des F
//si le philosophe prend 2 fourchettes d un coup, on se trouve dans une situation de famine potentielle.
	//essayons avec 1 fourchette a la fois
	//pthread_mutex_lock(&mutex);
	//*arg = n + 1;
	//pthread_mutex_unlock(&mutex);

	 //start critical section->lock
	//smallest fork



/*
pthread_mutex_lock(&F[smallest_fork]);

	printf("Philosopher %d has taken the smallest fork :  %d\n", n, smallest_fork);
	fflush(stdout);

//same fork
	//cas du last_philosophe : le dernier philosophe va prendre la fork n - 1

		//pthread_mutex_lock(&F[x]);//when philosopher 5 is eating he takes fork 1 and fork 5
		pthread_mutex_lock(&F[x]);

		printf("Philosopher %d has taken the biggest fork : %d\n", n, x);
		printf("%s, Philosopher %d is eating\n", ft_itoa((int)(get_time() - (*p).ptr->t_start)),n);
		fflush(stdout);

		(*p).nb_of_dinners++;

		ft_usleep(200);
		//End of critical section->unlock

		pthread_mutex_unlock(&F[x]);//la fourchette la plus grande
		pthread_mutex_unlock(&F[smallest_fork]);//la plus petite
	//	->trop lent. diviser les taches avec le modulo pour aller plus vite
*/
		printf("%s %d is sleeping\n",ft_itoa((int)(get_time() - (*p).ptr->t_start)), n);
		ft_usleep((*p).ptr->t_to_sleep);
		printf("%s %d is thinking \n",ft_itoa((int)(get_time() - (*p).ptr->t_start)), n);
	//pthread_mutex_unlock(&mutex);
		//ft_usleep(100);
		fflush(stdout);


}
	return (NULL);
}

int main(int argc, char *argv[])
{

	(void)argc;
	int i;
	int j;
	int l;
	int p;
	int	k;
	//void *msg;
	int			nb_of_philosophers;
	t_philo		*philos;
	t_ptr	*ptr;

	i = 0;
	nb_of_philosophers = ft_atoi(argv[1]);
	philos = malloc(sizeof(t_philo) * nb_of_philosophers);
	ptr = malloc(sizeof(t_ptr) * 1);
	//number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

	(*ptr).t_to_die = ft_atoi(argv[2]);
	(*ptr).t_to_eat = ft_atoi(argv[3]);

	(*ptr).t_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*ptr).nb_of_mandatory_meals = ft_atoi(argv[5]);
	else {
		(*ptr).nb_of_mandatory_meals = -1;
	}
	while (i < nb_of_philosophers)
	{
		philos[i].ptr = ptr;
		philos[i].nb_of_dinners = 0;
		philos[i].id = i + 1;
		if (i == (nb_of_philosophers - 1))
		{
			philos[i].flag_last_philosopher = 1;
		}
		else{
			philos[i].flag_last_philosopher = 0;
		}
		i++;
	}

	i = 0;
	(*ptr).t_start = get_time();

	if (nb_of_philosophers == 1)
	{
		ft_usleep((*ptr).t_to_die);
		printf("%s %d died\n", ft_itoa((int)(get_time() - ptr->t_start)),nb_of_philosophers);
		return(0);
	}

	while (i < nb_of_philosophers)
	{
		k = pthread_mutex_init(&F[i], NULL);//ou alors mais hors instructions 42, pthread_t_mutex F = PTHREAD_MUTEX_INITIALIZER; au lieu de pthread_mutex_init
		if (k == -1)
		{
			printf("Mutex initialization failed\n");
			exit(1);
		}
		i++;
	}


	j = 0;

	while (j < nb_of_philosophers)
	{

		k = pthread_create(&P[j], NULL, (void *)ft_start_routine, &philos[j]);
		//k = pthread_create(&P[j], NULL, (void *)ft_start_routine, &j);//envoi possibilite n1 : (void *)(long)i
		if (k != 0)
		{
			printf("Thread creation error \n");
			exit(1);
		}
		j++;

	}
	l = 0;
int w;
	while (l < nb_of_philosophers)
	{//l ordre du join est irrelevant , cela force juste a attendre la fin du fil d execution de thread
		w = pthread_join(P[l], NULL);// pthread_join(P[i], &msg) //Cette fonction force le programme principal a attendre jusqu'à ce que le thread en background appelé ait fini d'exécuter sa tâche.
		if (w != 0)
		{
			printf("Thread join failed \n");
			exit(1);
		}
		l++;
	}

	p = 0;

	while (p < nb_of_philosophers)
	{
		k = pthread_mutex_destroy(&F[p]);//ret 0 si success
		if (k!=0)
		{
			printf("Mutex not `Destroyed \n");
			exit(1);
		}
	p++;
	}
return 0;
}
