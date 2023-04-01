#include "philo.h"

static void	to_eat(t_philo *philo)
{
	philo->state = TAKEN_A_FORK;
	state_info(philo);
	state_info(philo);
	philo->state = EATING;
	state_info(philo);
}

static void	stop_eating(t_philo *philo)
{
	unlock_forks(philo);
	return ;
}

void	eating_process(t_philo *philo)
{
	lock_forks(philo);
	if (!is_alive(philo))
		return (stop_eating(philo));
	to_eat(philo);
	update_last_meal(philo);
	update_meals(philo);
	mssleep(philo->data->times->to_eat);
	unlock_forks(philo);
}
