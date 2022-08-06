/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:09:14 by zhatsago          #+#    #+#             */
/*   Updated: 2022/07/09 21:06:21 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	cmp_chars(char a, char b)
{
	if ((a - b) < 0)
		return (-1);
	else if ((a - b) == 0)
		return (0);
	return (1);
}

static int	cmp(int i, const char *str, int len)
{
	if (len == 11)
		len = 1;
	else
		len = 0;
	if (i == 0)
		return (cmp_chars('2', str[i + len]));
	if (i == 1)
		return (cmp_chars('1', str[i + len]));
	if (i == 2)
		return (cmp_chars('4', str[i + len]));
	if (i == 3)
		return (cmp_chars('7', str[i + len]));
	if (i == 4)
		return (cmp_chars('4', str[i + len]));
	if (i == 5)
		return (cmp_chars('8', str[i + len]));
	if (i == 6)
		return (cmp_chars('3', str[i + len]));
	if (i == 7)
		return (cmp_chars('6', str[i + len]));
	if (i == 8)
		return (cmp_chars('4', str[i + len]));
	if (i == 9)
		return (cmp_chars('7', str[i + len]));
	return (2);
}

static int	check_num(const char *str)
{
	int	i;
	int	res;
	int	len;

	res = 0;
	i = -1;
	while (str[++i] != '\0')
		if (!((str[i] >= '0' && str[i] <= '9') || (i == 0 && str[i] == '+')))
			return (-1);
	if (i > 11)
		return (-1);
	else if ((str[0] != '+' && i == 10) || (str[0] == '+' && i == 11))
	{
		len = i;
		i = -1;
		while (++i < 10)
		{
			res = cmp(i, str, len);
			if (res == -1 || res == 0)
				break ;
		}
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (check_num(str) == -1)
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}
