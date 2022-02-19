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
		perror("gettimeofday() failed");
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
		while(((curr_time() - start_time) < time_in_ms) && nb_intervals > 0 ) // 100 - 10ms < 200ms
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
