/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:37:28 by zhatsago          #+#    #+#             */
/*   Updated: 2022/07/17 17:39:43 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_time(long long time, struct s_state *state)
{
	long long	i;

	i = timeinterval();
	(void)state;
	while (true)
	{
		if ((timeinterval() - i) >= time)
			break ;
	}
}
