#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>//usleep
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>//gettimeofday





typedef struct s_ptr
{
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		t_start;
	int		nb_of_mandatory_meals;
}				t_ptr;


typedef struct s_philo
{

	int			id;
	int			flag_last_philosopher;
	int			nb_of_dinners;
	int			stop_dining;
	t_ptr		*ptr;

}				t_philo;

void	*ft_start_routine(void *arg);
void	ft_smallest_fork(t_philo *p, int n, int smallest_fork, int x);
void	ft_biggest_fork(t_philo *p, int n, int smallest_fork, int x);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		find_length(int n);
void	ft_usleep(unsigned int time_in_ms);
unsigned int	get_time(void);




#endif
