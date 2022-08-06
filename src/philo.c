/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:26:39 by zhatsago          #+#    #+#             */
/*   Updated: 2022/07/21 19:20:28 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	give_values_philo(t_philo **philo, int i, t_state *state,
					pthread_mutex_t *printing)
{
	philo[i] = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo[i]->id = i;
	philo[i]->eat_count = 0;
	philo[i]->last_meal = 0;
	philo[i]->is_dead = 0;
	philo[i]->born_time = -1;
	philo[i]->left_fork = i;
	philo[i]->right_fork = (i + 1) % state->phil_num;
	philo[i]->printing = printing;
	philo[i]->state = state;
	if (pthread_mutex_init(&(state->fork[i]), NULL))
	{
		error(6);
		return (0);
	}
	return (1);
}

t_philo	**init_philo(t_state *state)
{
	int				i;
	t_philo			**philo;
	pthread_mutex_t	printing;

	philo = (t_philo **)malloc(sizeof(t_philo) * (state->phil_num + 1));
	state->fork = malloc(sizeof(pthread_mutex_t) * (state->phil_num + 1));
	if (!philo || !state->fork)
		exit(0);
	philo[state->phil_num] = 0;
	if (pthread_mutex_init(&printing, NULL))
	{
		error(6);
		return (0);
	}
	i = 0;
	while (i < state->phil_num)
	{
		if (give_values_philo(philo, i, state, &printing) == 0)
			return (0);
		i++;
	}
	return (philo);
}
