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

int	init_stack(char **str, data_s **stack_a)
{
	data_s	*data_a;
	char	**str2;
	int		i;
	int		data;

	i = 1;
	data = 0;
	str = NULL;
	while (str[i] != NULL)
	{
		if (check_init(str[i]))
		{
			error_init(stack_a);
			return (1);
		}
		data = ft_atol(str[i]);
		data_a = mew_data(data);
		add_data(stack_a, data_a);
		i++;
	}
	return (0);
}
