#include "philo.h"

int start_process(int n, t_philo *philos)
{
    int         i;
    pthread_t   manager_thread;

    i = -1;
    philos->data->times->start_time = get_time();
    while(++i < n)
        pthread_create(&philos[i].id, NULL, &actions, &philos[i]);
    pthread_create(&manager_thread, NULL, &manager, philos);
    i = -1;
    while (++i < n)
        pthread_join(philos[i].id, NULL);
    pthread_join(manager_thread, NULL);
    return (0);
}

static int count_meals(t_philo *philos)
{
    int i;
    int count;

    count = 0;
    i = -1;
    while (++i < philos->data->number_of_philos)
    {
        if (get_meals(&philos[i]) == philos[i].data->times->must_eat)
            count++;
    }
    return (count);
}

static int  all_philos_ate(t_philo *philos)
{
    if (count_meals(philos) == philos->data->number_of_philos)
        return (TRUE);
    return (FALSE);
}

static int any_philo_die(t_philo *philos)
{
    int i;

    i = -1;
    while (++i < philos->data->number_of_philos)
    {
        if (timeout(&philos[i]))
        {
            to_kill(&philos[i]);
            philos[i].state = DIED;
            state_info(&philos[i]);
            return (TRUE);
        }
        mssleep(1);
    }
    return (FALSE);
}

void    *manager(void *arg)
{
    t_philo *philos;

    philos = (t_philo *) arg;
    while (!all_philos_ate(philos))
    {
        if (any_philo_die(philos))
            return (NULL);
    }
    return (NULL);
}
