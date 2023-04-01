#include "philo.h"

size_t  get_time(void)
{
    struct  timeval tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

size_t	get_time_now(size_t start_time)
{
	return (get_time() - start_time);
}

void	mssleep(size_t ms_time)
{
	size_t	initiated;

	initiated = get_time();
	while (ms_time > (get_time() - initiated))
		usleep(100);
}

int	timeout(t_philo *philo)
{
    size_t  current_time;
    size_t  last_meal;
    size_t  time_to_die;

    current_time = get_time_now(philo->data->times->start_time);
    last_meal = get_last_meal(philo);
    time_to_die = (size_t) philo->data->times->to_die;
    return ((current_time - last_meal) > time_to_die);
}
