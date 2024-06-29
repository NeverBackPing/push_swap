/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:18:49 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 13:46:25 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	single_data(char *data)
{
	int	check;

	check = 0;
	if (pars_array(data) == 0)
	{
		if (ft_signe(data) < 1)
		{
			if (!(data[0] == '-' && data[1] == '0'))
				NULL;
			else
				return (check = -1, check);
		}
		else
			return (check = -1, check);
	}
	else
		return (check = -1, check);
	return (check);
}

int	doublon(t_data **s, int c)
{
	t_data	*data_a;

	data_a = *s;
	while (data_a)
	{
		if ((int)data_a->content == c)
			return (1);
		data_a = data_a->next;
	}
	return (0);
}

int	array_data(t_data **stack_a)
{
	t_data	*data_a;
	t_data	*check;

	data_a = *stack_a;
	check = data_a;
	while (check)
	{
		data_a = data_a->next;
		if (doublon(&data_a, check->content))
			return (1);
		check = check->next;
	}
	return (0);
}
