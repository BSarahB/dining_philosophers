#include "philo.h"

void	ft_free_malloc_threads_P(pthread_t *P)
{
	if (P != NULL)
	{
		free(P);
		P = NULL;
	}
}

void	ft_free_malloc_mutex_F(pthread_mutex_t *F)
{
	if (F != NULL)
	{
		free(F);
		F = NULL;
	}
}

void	ft_free_struct_t_ptr(t_utils **ptr)
{
	ft_free_malloc_mutex_F((*ptr)->F);
	ft_free_malloc_threads_P((*ptr)->P);
	ft_free_malloc_threads_P((*ptr)->D);

	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_struct_t_philo(t_philo **p)
{
	ft_free_struct_t_ptr(&((*p)->ptr));
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

void	ft_free_struct_t_philo_only(t_philo **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
