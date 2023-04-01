#include "philo.h"

static int	is_valid_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) ||
				ft_atoi(argv[i]) > MAXINT ||
				ft_atoi(argv[i]) <= 0)
			{
				printf("Error!\n");
				return (FALSE);
			}
		}
	}
	return (TRUE);
}

void	validate_args(int argc, char **argv)
{
	if (!is_valid_number(argc, argv))
		exit(EXIT_FAILURE);
	if (argc > 6)
		printf("Too many args!\n");
	else if (argc < 5)
		printf("Too few args!\n");
	else
		return ;
	exit (EXIT_FAILURE);
}

int	is_alive(t_philo *philo)
{
	int	is_alive;

	pthread_mutex_lock(philo->data->lock_is_live);
	is_alive = FALSE;
	if (philo->data->is_alive)
		is_alive = philo->data->is_alive;
	pthread_mutex_unlock(philo->data->lock_is_live);
	return (is_alive);
}

void	to_kill(t_philo *philo)
{
	pthread_mutex_lock(philo->data->lock_is_live);
	philo->data->is_alive = FALSE;
	pthread_mutex_unlock(philo->data->lock_is_live);
}
