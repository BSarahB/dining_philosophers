/*BUGG NANI
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

void *ft_start_routine(void *arg)
{
	t_philo	*p;
	char *chrono_sleep;
	char *chrono_think;


	p = (t_philo *)arg;
//	(*p).ptr->stop_dining_all = 0;
//pour eviter deadlock et famine on va ordonner les ressources et on imposera de prendre d abord la plus petite fork
	ft_call_death_check(p);
	//print_debug(p, "THREAD ENTERING THE ROUTINE\n\n\n");

	while ((*p).ptr->stop_dining_all == 0)
	{

	//pthread_mutex_lock(&mutex);

	int n;
	int x;
	int smallest_fork;

	/* //1 ere possibilite de cast
	n = (long)arg;
	*/
	//2 eme possibilite de cast:

	n = ((*(t_philo *)arg).id); //cqfd TODO//n 2
	x = ((*(t_philo *)arg).id);//x 2
int flag_last = (*(t_philo *)arg).flag_last_philosopher;

smallest_fork = n - 1;// sf = 2- 1 = 1
if (flag_last == 1)// 2 est le dernier philosoph
{
	smallest_fork = 0;//pour le last_philosopher pair: F[0]
	x = n - 1;
}
else
	x = n;

if ((*p).ptr->stop_dining_all != 1)
{
	if ((*p).ptr->nb_of_philosophers % 2 == 0) //nb philos pair
	{
		if (n % 2 != 0 || flag_last == 1) //si philosophe id est impair
			ft_smallest_fork(p, n, smallest_fork, x);
		else
			ft_biggest_fork(p, n, smallest_fork, x);
	}
	else{
		if (n % 2 == 0 || flag_last == 1 || n == 1)//id pair, dernier philosoph ou premier vont chopper le smallest fourchette
			ft_smallest_fork(p, n, smallest_fork, x);
		else{
			ft_biggest_fork(p, n, smallest_fork, x);
		}
	}


}

//ft_smallest_fork(p, n, smallest_fork, x);
if ((*p).ptr->nb_of_mandatory_meals != -1 && (*p).nb_of_dinners == (*p).ptr->nb_of_mandatory_meals)
{
	//lock? et unlock necessaire ou pas?
	(*p).ptr->nb_of_plumpy_philos++;
	if ((*p).ptr->nb_of_plumpy_philos == (*p).ptr->nb_of_philosophers)
		(*p).ptr->stop_dining_all = 1;
	return (NULL);
}

if ((*p).ptr->stop_dining_all != 1)
{
	//printf(" curr_philo = %d, value of stop_dinning = %d\n",n, (*p).ptr->stop_dining_all);
		chrono_sleep = ft_itoa((int)(curr_time() - (*p).ptr->t_start));
		printf("%s %d is sleeping\n",chrono_sleep, n);
		ft_free_str(chrono_sleep);
		ft_call_usleep((*p).ptr->t_to_sleep);
		if ((*p).ptr->stop_dining_all != 1)
		{
			chrono_think = ft_itoa((int)(curr_time() - (*p).ptr->t_start));
			printf("%s %d is thinking \n",chrono_think, n);
	//pthread_mutex_unlock(&mutex);
			usleep(100);
			ft_free_str(chrono_think);
		//printf("ok usleep 100 de %d\n", n);
	}
		fflush(stdout);
}
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
	int			nb_of_philosophers;
	char *chrono;
	t_philo		*philos;
	t_ptr	*ptr;

	i = 0;
	nb_of_philosophers = ft_atoi(argv[1]);
	philos = malloc(sizeof(t_philo) * nb_of_philosophers);
	ptr = malloc(sizeof(t_ptr) * 1);
	//syntax blyat: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
	(*ptr).nb_of_philosophers = nb_of_philosophers;
	(*ptr).t_to_die = ft_atoi(argv[2]);
	(*ptr).t_to_eat = ft_atoi(argv[3]);

	(*ptr).t_to_sleep = ft_atoi(argv[4]);
	(*ptr).stop_dining_all = 0;
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
	(*ptr).t_start = curr_time();

	if (nb_of_philosophers == 1)
	{
		ft_call_usleep((*ptr).t_to_die);
		chrono = ft_itoa((int)(curr_time() - ptr->t_start));
		printf("%s %d died\n",chrono, nb_of_philosophers);

		ft_free_struct_t_philo(&philos);
		ft_free_str(chrono);

		return(0);
	}

	while (i < nb_of_philosophers)//0, 1, 2, 3
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

	while (j < nb_of_philosophers)//0, 1 , 2 , 3
	{
		philos[j].last_meal_time = curr_time();//ou t_start?

		k = pthread_create(&P[j], NULL, (void *)ft_start_routine, &philos[j]);//P[0, 1, 2, 3]
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
			printf("Mutex not Destroyed \n");
			exit(1);
		}
	p++;
	}
	ft_free_struct_t_philo(&philos);

return 0;
}
