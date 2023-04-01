#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAXINT 2147483647

typedef pthread_mutex_t	t_fork;

typedef enum e_state
{
	TAKEN_A_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_state;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_times
{
	size_t		start_time;
	int			to_die;
	int			to_eat;
	int			to_sleep;
	int			must_eat;
}	t_times;

typedef struct s_data
{
	int				is_only_one;
	int				number_of_philos;
	int				is_alive;
	t_times			*times;
	pthread_mutex_t	*lock_info;
	pthread_mutex_t	*lock_is_live;
	pthread_mutex_t	*lock_state;
}	t_data;

typedef struct s_philo
{
	int				number;
	int				state;
	int				meals;
	size_t			last_meal;
	pthread_t		id;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*lock_last_meal;
	pthread_mutex_t	*lock_meals;
	t_data			*data;
}	t_philo;

typedef struct s_init
{
	t_data	data;
	t_fork	*forks;
	t_philo	*philos;
}	t_init;

//INIT
void	init_all(int argc, char **argv, t_init *init);

//LIB
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		max(int a, int b);
int		min(int a, int b);

//INFO
void	state_info(t_philo *philo);

//UTILS
void	validate_args(int argc, char **argv);
int		is_alive(t_philo *philo);
int		to_kill(t_philo *philo);

// TIMES
void	mssleep(size_t ms_time);
size_t	get_time(void);
size_t	get_time_now(size_t start_time);
int		timeout(t_philo *philo);

//PHILO
int		start_process(int n, t_philo *philos);
void	*manager(void *arg);

//MEALS
int		get_meals(t_philo *philo);
void	update_meals(t_philo *philo);
size_t	get_last_meal(t_philo *philo);
void	update_last_meal(t_philo *philo);

//ACTIONS
void	*actions(void *ptr);

//EXIT
void	finish_process(int n, t_data *data, t_fork *forks, t_philo *philos);

//FORKS
void	lock_forks(t_philo *philo);
void	unlock_forks(t_philo *philo);

//EATING PROCESS
void	eating_process(t_philo *philo);
#endif