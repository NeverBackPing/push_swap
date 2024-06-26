/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/22 16:40:14 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	ft_digit_array(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
		i++;
	}
	return (0);
}
int pars_array(char **str)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		while (str[i][j] != '\0')
		{
			if (ft_digit_array(&str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	init_stack(char **str, data_s **stack_a)
{
	data_s	*data_a;
	int		data;
	int		check;
	int		i;

	i = 1;
	data = 0;
	check = 0;
	while (str[i] != NULL)
	{
		check = check_init(str[i], stack_a);
		if (check == -1)
		{
			error_init(stack_a);
			return (1);
		}
		if (check == 2)
			NULL;
		if (check == 0)
		{
			data = ft_atol(str[i]);
			data_a = mew_data(data);
			add_data(stack_a, data_a);
		}
		i++;
	}
	return (0);
}
