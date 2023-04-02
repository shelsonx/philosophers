#include "philo.h"

static char	*get_state_message(int state)
{
	if (state == TAKEN_A_FORK)
		return ("has taken a fork");
	else if (state == EATING)
		return ("is eating");
	else if (state == THINKING)
		return ("is thinking");
	else if (state == SLEEPING)
		return ("is sleeping");
	else if (state == DIED)
		return ("died");
	else
		return (NULL);
}

void	state_info(t_philo *philo)
{
	char	*state_message;
	int		state;

	pthread_mutex_lock(philo->data->lock_info);
	state = philo->state;
	state_message = get_state_message(state);
	if (state_message)
		printf("%5ld Philosopher %2d %s\n",
			get_time_now(philo->data->times->start_time),
			philo->number, state_message);
	pthread_mutex_unlock(philo->data->lock_info);
}
