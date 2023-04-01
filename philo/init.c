#include "philo.h"

static void	init_args(int argc, char **argv, t_data *data)
{
	data->times = malloc(sizeof(t_times));
	data->number_of_philos = ft_atoi(argv[1]);
	data->times->to_die = ft_atoi(argv[2]);
	data->times->to_eat = ft_atoi(argv[3]);
	data->times->to_sleep = ft_atoi(argv[4]);
	data->times->must_eat = -1;
	if (argc == 6)
		data->times->must_eat = ft_atoi(argv[5]);
}

static void	init_data(t_data *data, pthread_mutex_t *forks, t_philo *philos)
{
	forks = NULL;
	philos = NULL;
	if (data->number_of_philos == 1)
		data->is_only_one = TRUE;
	else
		data->is_only_one = FALSE;
	data->is_alive = TRUE;
	data->times->start_time = 0;
	data->lock_info = malloc(sizeof(t_fork));
	data->lock_is_live = malloc(sizeof(t_fork));
	data->lock_state = malloc(sizeof(t_fork));
	if (data->lock_info == NULL || data->lock_is_live == NULL)
		finish_process(0, data, forks, philos);
	pthread_mutex_init(data->lock_info, NULL);
	pthread_mutex_init(data->lock_is_live, NULL);
	pthread_mutex_init(data->lock_state, NULL);
}

static void	init_forks(int n, t_data *data, t_fork **forks, t_philo **philos)
{
	int	i;

	*forks = malloc(sizeof(t_fork) * n);
	if (*forks == NULL)
		finish_process(n, data, *forks, *philos);
	i = -1;
	while (++i < n)
		pthread_mutex_init(&(*forks)[i], NULL);
}

static void	init_philos(int n, t_data *data, t_fork **forks, t_philo **philos)
{
	int	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * n);
	if (*philos == NULL)
		finish_process(n, data, *forks, *philos);
	i = -1;
	while (++i < n)
	{
		(*philos)[i].fork_right = &(*forks)[max(i, (i + 1) % n)];
		(*philos)[i].fork_left = &(*forks)[min(i, (i + 1) % n)];
		(*philos)[i].lock_last_meal = malloc(sizeof(t_fork));
		(*philos)[i].lock_meals = malloc(sizeof(t_fork));
		(*philos)[i].number = i + 1;
		(*philos)[i].meals = 0;
		(*philos)[i].data = data;
		(*philos)[i].state = -1;
		pthread_mutex_init((*philos)[i].lock_last_meal, NULL);
		pthread_mutex_init((*philos)[i].lock_meals, NULL);
	}
}

void	init_all(int argc, char **argv, t_init *init)
{
	init_args(argc, argv, &init->data);
	init_data(&init->data, init->forks, init->philos);
	init_forks(init->data.number_of_philos, &init->data,
		&init->forks, &init->philos);
	init_philos(init->data.number_of_philos, &init->data,
		&init->forks, &init->philos);
}
