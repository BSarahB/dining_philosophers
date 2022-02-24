#include "philo.h"

pthread_mutex_t mutex_debug_msg = PTHREAD_MUTEX_INITIALIZER;


void	*ft_start_routine666(void *arg)
{
	t_philo	*p;
	int		stop;
	char	*chrono_death;
	int	flag_already_died;

	p = (t_philo *)arg;
	stop = 0;
	flag_already_died = 0;
    ft_printf("D%d starts 666\n",get_id(p));

	//if((*p).ptr->flag_already_died == 1 )
//	{
		//pthread_detach((*p).D);
        //ft_printf("D%d DETACHED BEGIN\n",(*p).id);
	//	return (NULL);
	//}
    while (!stop && get_stop_dining_all(p->ptr) == 0)
	{
        if ((curr_time() - get_last_meal_time(p)) >= (unsigned int)get_t_to_die(p->ptr))
        {
			pthread_mutex_lock(&(*p).ptr->mutex666);
            if(get_flag_already_died(p->ptr) == 1 )
			{
		//		pthread_detach((*p).D);
            //	ft_printf("D%d DETACHED FLAG \n",(*p).id);
				pthread_mutex_unlock(&(*p).ptr->mutex666);
				return (NULL);
			}
            set_stop_dining_all(p->ptr,1);

			stop = 1;
            chrono_death = ft_itoa((int)(curr_time() - get_t_start(p->ptr)));
			if (flag_already_died == 0)
			{
				flag_already_died = 1;
                set_flag_already_died(p->ptr,1);
                ft_printf("%s %d DIED\n", chrono_death, get_id(p));
				pthread_mutex_unlock(&(*p).ptr->mutex666);
                ft_printf("p : %d, meal_count = %d\n", get_id(p), get_nb_of_dinners(p));
			}
			ft_free_str(chrono_death);
			//pthread_detach((*p).D);
        //	ft_printf("D%d DETACHED DEATH \n",(*p).id);

			return (NULL);
		}
		else {
            stop = get_stop_dining_all(p->ptr) + stop;
		}
	}
	//pthread_detach((*p).D);
    //ft_printf("D%d DETACHED END\n",(*p).id);
	return (NULL);
}

