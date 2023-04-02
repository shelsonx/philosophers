#include "philo.h"

static void	*is_only_one(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->lock_state);
	philo->state = TAKEN_A_FORK;
	state_info(philo);
	philo->state = DIED;
	state_info(philo);
	pthread_mutex_unlock(philo->lock_state);
	pthread_mutex_unlock(philo->fork_left);
	return (NULL);
}

static void	to_sleep(t_philo *philo)
{
	if (!is_alive(philo))
		return ;
	pthread_mutex_lock(philo->lock_state);
	philo->state = SLEEPING;
	pthread_mutex_unlock(philo->lock_state);
	state_info(philo);
	mssleep(philo->data->times->to_sleep);
}

static void	to_think(t_philo *philo)
{
	if (!is_alive(philo))
		return ;
	pthread_mutex_lock(philo->lock_state);
	philo->state = THINKING;
	pthread_mutex_unlock(philo->lock_state);
	state_info(philo);
}

static int	start_dinner(t_philo *philo)
{
	while (is_alive(philo))
	{
		eating_process(philo);
		if (get_meals(philo) == philo->data->times->must_eat)
			return (FALSE);
		to_sleep(philo);
		to_think(philo);
	}
	return (TRUE);
}

void	*actions(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->data->is_only_one)
		return (is_only_one(philo));
	if (!start_dinner(philo))
		return (NULL);
	return (NULL);
}
