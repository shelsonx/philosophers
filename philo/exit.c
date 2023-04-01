#include "philo.h"

static void free_structs(t_data *data, t_mutex *forks, t_philo *philos)
{
    free(data->lock_info);
    free(data->lock_is_live);
    free(data->times);
    free(forks);
    free(philos);
}

static void free_locks_meals(t_philo *philo)
{
    free(philo->lock_last_meal);
    free(philo->lock_meals);
}

static void destroy_locks_meal(t_philo *philo)
{
    if (philo->lock_last_meal)
        pthread_mutex_destroy(philo->lock_last_meal);
    if (philo->lock_meals)
        pthread_mutex_destroy(philo->lock_meals);
}

static void destroy_others_locks(t_data *data)
{
    if (data->lock_info)
        pthread_mutex_destroy(data->lock_info);
    if (data->lock_is_live)
        pthread_mutex_destroy(data->lock_is_live);
}

void    finish_process(int n, t_data *data, t_mutex *forks, t_philo *philos)
{
    int i;

    i = -1;
    while (++i < n && forks)
        pthread_mutex_destroy(&forks[i]);
    i = -1;
    while (++i < n && philos)
    {
        destroy_locks_meal(&philos[i]);
        free_locks_meals(&philos[i]);
    }
    destroy_others_locks(data);
    free_structs(data, forks, philos);
}

