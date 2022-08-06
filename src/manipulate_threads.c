/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_threads.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:53:47 by zhatsago          #+#    #+#             */
/*   Updated: 2022/07/17 17:36:30 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	eating_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo->state->fork[philo->left_fork]));
	print_action(philo, "has taken the left fork");
	pthread_mutex_lock(&(philo->state->fork[philo->right_fork]));
	if (philo->is_dead == 1)
		return (1);
	print_action(philo, "has taken the right fork");
	print_action(philo, "is eating");
	philo->last_meal = timeinterval();
	wait_time(philo->state->time_to_eat, philo->state);
	(philo->eat_count)++;
	return (0);
}

static void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 != 0)
		usleep(20000);
	while (true)
	{
		if (eating_philo(philo) == 1)
			break ;
		print_action(philo, "is sleeping");
		pthread_mutex_unlock(&(philo->state->fork[philo->left_fork]));
		pthread_mutex_unlock(&(philo->state->fork[philo->right_fork]));
		wait_time(philo->state->time_to_sleep, philo->state);
		print_action(philo, "is thinking");
	}
	return (NULL);
}

int	manipulate_threads(t_philo **philo, t_state *state)
{
	int			i;
	pthread_t	dead;

	i = -1;
	pthread_create(&dead, NULL, dead_checker, (void *)philo);
	while (philo[++i] != 0)
	{
		philo[i]->born_time = timeinterval();
		philo[i]->last_meal = timeinterval();
		if (pthread_create(&(philo[i]->thread), 0, routine, (void *)(philo[i])))
			return (1);
	}
	pthread_join(dead, NULL);
	i = -1;
	while (++i < state->phil_num)
		pthread_mutex_destroy(&(state->fork[i]));
	pthread_mutex_destroy(philo[0]->printing);
	return (0);
}
