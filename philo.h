#ifndef PHILO_H
# define PHILO_H
#include <unistd.h>//usleep
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>//gettimeofday
#include <stdarg.h>

#define PRINT_DEBUG
void ft_printf(const char * format, ...);

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
	int					flag_already_died;
	pthread_t			*P;
	pthread_t			*D;
	pthread_mutex_t		*F;
	pthread_mutex_t		mutex_protect;
	pthread_mutex_t		mutex666;
	pthread_mutex_t		mutex_stop;

}						t_utils;

typedef struct s_philo
{

	int					id;
	int					flag_last_philosopher;
	int					nb_of_dinners;
	int					stop_dining_all_p;
	t_utils				*ptr;
	int					last_meal_time;
	pthread_mutex_t		mutex_protect;

}						t_philo;


void			*ft_start_routine(void *arg);
void			ft_smallest_fork(t_philo *p, int smallest_fork, int x);
void			ft_biggest_fork(t_philo *p, int smallest_fork, int x);
long			ft_atoi(const char *str);
char			*ft_itoa(int n);
int				find_length(int n);
void			ft_call_usleep(unsigned int time_in_ms);
unsigned int	curr_time(void);
void			*ft_call_death_check(t_philo *p);
void			ft_free_str(char *str);
void			ft_free_struct_t_philo(t_philo **p);
void			ft_free_struct_t_ptr(t_utils **ptr);
void			ft_free_struct_t_philo_only(t_philo **p);
void			ft_free_malloc_mutex_F(pthread_mutex_t *F);
void			ft_free_malloc_threads_P(pthread_t *P);
int				ft_check_validity(int argc, char *argv[]);
int				ft_check_validity2(int argc, char *argv[], t_utils *ptr,t_philo *philos);
int				ft_check_error(char **argv);
int				ft_check_int_max(int argc, char **argv);
void			ft_init_ptr(t_utils *ptr, char *argv[], pthread_t *P, pthread_t *D, pthread_mutex_t *F);
int				ft_mandatory_meals(int argc, char *argv[], t_utils *ptr);
void			ft_init_philosophers(t_philo *philos, t_utils *ptr);
void			ft_error(char *const str);
void			ft_putstr_fd(char *s, int fd);
int				ft_only_one_philo(t_utils *ptr, t_philo *philos);
int				ft_mutex_init(t_utils *ptr, pthread_mutex_t *F, t_philo *philos);
int				ft_thread_create(t_utils *ptr, t_philo *philos, pthread_t *P, pthread_t *D);
int				ft_thread_join(t_utils *ptr, pthread_t *P, pthread_t *D, t_philo *philos);
int				ft_mutex_destroy(t_utils *ptr, t_philo *philos, pthread_mutex_t *F, int p);
void			*ft_start_routine666(void *arg);
void			ft_call_ft_printf(t_philo *p, char c, char *chrono);
unsigned int	ft_calculate_time_to_exec_function(void);
void			ft_printf(const char * format, ...);
void			ft_printf_debug(const char * format, ...);
int				read_protected_int(pthread_mutex_t * mutex, int * var);
int				*read_protected_int_star(pthread_mutex_t * mutex, int *var);
void			write_protected_int(pthread_mutex_t * mutex, int * var, const int value);
pthread_t		read_protected_pthread_t(pthread_mutex_t * mutex, pthread_t * var);
pthread_t		*read_protected_pthread_t_star(pthread_mutex_t * mutex, pthread_t * var);
void			write_protected_pthread_t(pthread_mutex_t * mutex, pthread_t * var, const pthread_t value);
t_utils			read_protected_t_utils(pthread_mutex_t * mutex, t_utils * var);
t_utils			*read_protected_t_utils_star(pthread_mutex_t * mutex, t_utils * var);
void			write_protected_t_utils(pthread_mutex_t * mutex, t_utils * var, const t_utils value);
int				get_t_to_die(t_utils * ptr);
int				get_t_to_eat(t_utils * ptr);
int				get_t_to_sleep(t_utils * ptr);
int				get_t_start(t_utils * ptr);
int				get_nb_of_mandatory_meals(t_utils * ptr);
int				get_nb_of_plumpy_philos(t_utils * ptr);
int				get_stop_dining_all(t_utils * ptr);
int				get_nb_of_philosophers(t_utils * ptr);
int				get_flag_already_died(t_utils * ptr);
void			set_t_to_die(t_utils * ptr, int value);
void			set_t_to_eat(t_utils * ptr, int value);
void			set_t_to_sleep(t_utils * ptr, int value);
void			set_t_start(t_utils * ptr, int value);
void			set_nb_of_mandatory_meals(t_utils * ptr, int value);
void			set_nb_of_plumpy_philos(t_utils * ptr, int value);
void			set_stop_dining_all(t_utils * ptr, int value);
void			set_nb_of_philosophers(t_utils * ptr, int value);
void			set_flag_already_died(t_utils * ptr, int value);
int				get_id(t_philo * p);
int				get_flag_last_philosopher(t_philo * p);
int				get_stop_dining_all_p(t_philo * p);
int				get_nb_of_dinners(t_philo * p);
int				get_last_meal_time(t_philo * p);
void			set_id(t_philo * p, int value);
void			set_flag_last_philosopher(t_philo * p, int value);
void			set_stop_dining_all_p(t_philo * p, int value);
void			set_nb_of_dinners(t_philo * p, int value);
void			set_last_meal_time(t_philo * p, int value);

#endif
