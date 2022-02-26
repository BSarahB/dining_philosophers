#include "philo.h"

void ft_printf(const char * format, ...)
{
#ifdef PRINT_DEBUG
	va_list argptr;
	va_start(argptr, format);
	vfprintf(stderr, format, argptr);
	va_end(argptr);
	fflush(stdout);
#endif
}


void ft_printf_debug(const char * format, ...)
{
#ifdef PRINT_DEBUG
	va_list argptr;
	va_start(argptr, format);
	vfprintf(stderr, format, argptr);
	va_end(argptr);
	fflush(stdout);
#endif
}
/*
void ft_print_debug(t_philo *p, char const *s)
{
	//ne sera compile pas juste execute, que si debug == qq chose , soit deifni
#ifdef DEBUG
	int n;

	n = (*p).id;
    ft_printf("%d %s", n, s);
#endif
}
*/

int		find_length(int n)
{
	int length;

	length = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		length;
	long	nb;

	nb = n;
	length = find_length(n);
	if (!(result = (char *)malloc(sizeof(*result) * length + 1)))
		return (NULL);
	result[length] = '\0';
	if (nb < 0)
		result[0] = '-';
	else if (nb == 0)
		result[0] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		--length;
		result[length] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (result);
}

long	ft_atoi(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' \
		 || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	result = sign * result;
	return (result);
}
