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
number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
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

//