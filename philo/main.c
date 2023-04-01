#include "philo.h"

int	main(int argc, char **argv)
{
	t_init	*init;

	validate_args(argc, argv);
	init = malloc(sizeof(t_init));
	init_all(argc, argv, init);
	start_process(init->data.number_of_philos, init->philos);
	finish_process(init->data.number_of_philos,
		&init->data, init->forks, init->philos);
	free(init);
	return (0);
}
