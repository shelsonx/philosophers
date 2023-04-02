#include "philo.h"

static void	to_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_state);
	philo->state = TAKEN_A_FORK;
	pthread_mutex_unlock(philo->lock_state);
	state_info(philo);
	state_info(philo);
	pthread_mutex_lock(philo->lock_state);
	philo->state = EATING;
	pthread_mutex_unlock(philo->lock_state);
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
	mssleep(philo->data->times->to_eat);
	unlock_forks(philo);
	update_meals(philo);
}
