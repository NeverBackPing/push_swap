/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/22 16:40:14 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	error_init(data_s **lst)
{
	data_clear(lst);
	write(-1, "Error\n", 5);
}

int	check_overflow(char *data)
{
	long	num;

	num = ft_atoi(data);
	if (num > 2147483647 || num < -2147483647)
		return (1);
	return (0);
}

int	check_init(char *data)
{
	int		check;
	int		i;

	i = 0;
	check = 0;
	while(data[i])
	{
		if (ft_isdigit(data[i]))
		{
			if (ft_atoi(data) < 0)
				break ;
			check = 1;
			return (check);
		}
		i++;
	}
	if (check_overflow(data))
	{
		check = 1;
		return (check);
	}
	return (check);
}
