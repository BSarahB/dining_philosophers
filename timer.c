#include "philo.h"

unsigned int	curr_time(void)
{
	unsigned int	curr_time;
	struct timeval	time;
	unsigned int	sec_to_ms;
	unsigned int	usec_to_ms;

	curr_time = 0;
	if (gettimeofday(&time, NULL) == -1)
	{
		printf("gettimeofday() failed");
		return (0);
	}
	sec_to_ms = time.tv_sec * 1000;
	usec_to_ms = time.tv_usec / 1000;
	curr_time = sec_to_ms + usec_to_ms;
	return (curr_time);
}

void	ft_call_usleep(unsigned int time_in_ms)
{
	unsigned int	start_time;
	int				nb_intervals;
	unsigned int	last_interval_ms;

	start_time = curr_time();
	nb_intervals = 1;
	last_interval_ms = 0;
	if (time_in_ms > 1000)
	{
		nb_intervals = time_in_ms / 1000;
		last_interval_ms = time_in_ms % 1000;
		while(((curr_time() - start_time) < time_in_ms) && nb_intervals > 0 )
		{
			usleep(1000000);
			nb_intervals --;
		}
		if ((curr_time() - start_time) < time_in_ms)
			usleep(last_interval_ms * 1000);
	}
	else
		usleep(time_in_ms * 1000);
}

unsigned int	ft_calculate_time_to_exec_function(void)
{
	unsigned int mem_time;
	unsigned int first_time;
	unsigned int current_time;
	unsigned int measured_time;

	mem_time = 0;
	first_time = 1;
	if(first_time == 1)
	{
		mem_time = curr_time();
		first_time = 0;
		return(0);
	}
	else
	{
		current_time = curr_time();
		measured_time =  current_time - mem_time;
		printf("le temps ecoule en ms : %u\n", measured_time);
		first_time = 1;
		return(measured_time);
	}
}
