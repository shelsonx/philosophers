#include "philo.h"

int	get_meals(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(philo->lock_meals);
	meals = philo->meals;
	pthread_mutex_unlock(philo->lock_meals);
	return (meals);
}

void	update_meals(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_meals);
	philo->meals++;
	pthread_mutex_unlock(philo->lock_meals);
}

size_t	get_last_meal(t_philo *philo)
{
	size_t	last_meal;

	pthread_mutex_lock(philo->lock_last_meal);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(philo->lock_last_meal);
	return (last_meal);
}

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_last_meal);
	philo->last_meal = get_time_now(philo->data->times->start_time);
	pthread_mutex_unlock(philo->lock_last_meal);
}
