#include "philo.h"

int	ft_only_one_philo(t_utils *ptr, t_philo *philos)
{
	char	*chrono;

	if ((*ptr).nb_of_philosophers == 1)
	{
		ft_call_usleep((*ptr).t_to_die);
		chrono = ft_itoa((int)(curr_time() - ptr->t_start));
		printf("%s %d died\n",chrono, (*ptr).nb_of_philosophers);
		//TODO ft_free_struct_t_philo(&philos) / free les mallocs des threads P/ free les mallocs mutex F / free ptr
		//msg d erreurs
		ft_free_struct_t_philo(&philos);
		ft_free_str(chrono);
		return(1);//GERER LE RETURN TODO
	}
	return (0);
}
