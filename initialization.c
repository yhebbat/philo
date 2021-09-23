#include "philo.h"

void	init_mutex(t_args *args)
{
	int	i;

	i = -1;
	args->forks = malloc(args->number_philo * sizeof(pthread_mutex_t));
	while (++i < args->number_philo)
		pthread_mutex_init(&args->forks[i], NULL);
	pthread_mutex_init(&args->write, NULL);
	pthread_mutex_init(&args->is_eating, NULL);
}

t_philo	*init_philo(t_args *args)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * args->number_philo);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < args->number_philo)
	{
		philo[i].args = args;
		philo[i].philo_id = i;
		philo[i].nb_of_meals = args->num_meal;
		philo[i].eat = 0;
		philo[i].start = 0;
		philo[i].last_time_eat = 0;
	}
	return (philo);
}
