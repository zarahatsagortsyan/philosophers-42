/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:37:12 by zhatsago          #+#    #+#             */
/*   Updated: 2022/07/17 17:37:47 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_action(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->printing);
	printf("%lld %d %s\n", \
			timeinterval() - philo->born_time, philo->id + 1, str);
	pthread_mutex_unlock(philo->printing);
}
