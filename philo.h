#ifndef PHILO_H
# define PHILO_H
#include <unistd.h>//usleep
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>//gettimeofday

typedef struct s_utils
{
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					t_start;
	int					nb_of_mandatory_meals;
	int					nb_of_plumpy_philos;
	int					stop_dining_all;
	int					nb_of_philosophers;
	pthread_t			*P;
	pthread_mutex_t		*F;
}				t_utils;

typedef struct s_philo
{

	int			id;
	int			flag_last_philosopher;
	int			nb_of_dinners;
	t_utils		*ptr;
	int			last_meal_time;
	pthread_t	D;
}				t_philo;

void			*ft_start_routine(void *arg);
void			*ft_start_routine2(void *arg);
void			ft_smallest_fork(t_philo *p, int n, int smallest_fork, int x);
void			ft_biggest_fork(t_philo *p, int n, int smallest_fork, int x);
long			ft_atoi(const char *str);
char			*ft_itoa(int n);
int				find_length(int n);
void			ft_call_usleep(unsigned int time_in_ms);
unsigned int	curr_time(void);
void			*ft_call_death_check(t_philo *p);
void			print_debug(t_philo *p, char const *s);
void			ft_free_str(char *str);
void			ft_free_struct_t_ptr(t_utils **ptr);
void			ft_free_struct_t_philo(t_philo **p);
int				ft_check_validity(int argc, char *argv[]);
int				ft_check_validity2(int argc, char *argv[], t_utils *ptr);
int				ft_check_error(char **argv);
int				ft_check_int_max(int argc, char **argv);
void			ft_init_ptr(t_utils *ptr, char *argv[], pthread_t *P, pthread_mutex_t *F);
int				ft_mandatory_meals(int argc, char *argv[], t_utils *ptr);
void			ft_init_philosophers(t_philo *philos, t_utils *ptr);
void			ft_error(char *const str);
void			ft_putstr_fd(char *s, int fd);
int				ft_only_one_philo(t_utils *ptr, t_philo *philos);

#endif
