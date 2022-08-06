/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <zhatsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:27:59 by zhatsago          #+#    #+#             */
/*   Updated: 2022/07/21 19:10:38 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_arguments(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0)
		return (error(1));
	if (ft_atoi(argv[2]) <= 0)
		return (error(2));
	if (ft_atoi(argv[3]) <= 0)
		return (error(3));
	if (ft_atoi(argv[4]) <= 0)
		return (error(4));
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
			return (error(5));
	}
	return (1);
}

int	error(int condition)
{
	if (condition == 1)
		printf("wrong number of philos\n");
	else if (condition == 2)
		printf("wrong parameter (time to die)\n");
	else if (condition == 3)
		printf("wrong parameter (time to eat)\n");
	else if (condition == 4)
		printf("wrong  parameter (time to sleep)\n");
	else if (condition == 5)
		printf("wrong parameter (number of times philo must eat)\n");
	else if (condition == 6)
		printf("mutex initialization error\n");
	return (0);
}
