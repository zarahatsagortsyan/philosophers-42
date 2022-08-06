/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:12:32 by zhatsago          #+#    #+#             */
/*   Updated: 2022/07/20 21:21:11 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	death(t_philo *philo, int *finish_eating)
{
	philo->is_dead = 1;
	print_action(philo, "died");
	*finish_eating = -1;
}

static void	eat_all(int	*eat_finish, t_philo **philo, int i)
{
	if (philo[0]->state->num_eaten != -1 && \
			philo[i]->eat_count >= philo[0]->state->num_eaten)
		++(*eat_finish);
}

void	*dead_checker(void *args)
{
	int		i;
	int		finish_eating;
	t_philo	**philo;

	philo = (t_philo **)args;
	usleep(15000);
	while (1)
	{
		finish_eating = 0;
		i = -1;
		while (++i < philo[0]->state->phil_num)
		{
			if (((timeinterval() - philo[i]->last_meal + 1) > \
				philo[0]->state->time_to_die) && philo[i]->born_time > 0)
			{
				death(philo[i], &finish_eating);
				break ;
			}
			eat_all(&finish_eating, philo, i);
		}
		if (finish_eating == philo[0]->state->phil_num || finish_eating == -1)
			break ;
	}
	return (0);
}
