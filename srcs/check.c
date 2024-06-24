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
	write(2, "Error\n", 6);
}

int	check_overflow(char *data)
{
	long	num;

	num = ft_atol(data);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

void	check_space(char **str, char *data);
{
	if (isspace(data))
	{
		str = 
	}
}

int	check_init(char *data)
{
	char	**str;
	int		check;
	int		i;

	i = 0;
	check = 0;
	while(data[i])
	{
		if (ft_isdigit(data[i]))
		{
			if (ft_atol(data) < 0 || ft_signe(data[i]))
				break ;
			check = 1;
			return (check);
		}
		i++;
	}
	if (check_overflow(data) || ft_atol(data) == 0)
		check = 1;
	return (check);
}
