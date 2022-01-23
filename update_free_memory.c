#include "philo.h"

void	ft_free_str(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}


void	ft_free_struct_t_ptr(t_ptr **ptr)
{
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
