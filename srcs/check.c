/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 15:11:16 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	check_overflow(char *data)
{
	long	num;

	num = ft_atol((char *)data);
	if (num > INT_MAX || num < INT_MIN)
		return (-1);
	return (0);
}

int	check_data(char *data)
{
	int	check;

	check = 0;
	if (ft_isdigit(data) > -1)
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

int	check_format(char *str, int content, t_data **stack)
{
	int		check;
	t_data	*data_a;

	check = 0;
	check = check_data(str);
	check = check_overflow(str);
	if (check == -1 || pars_array(str))
		return (check = -1, check);
	content = ft_atol(str);
	data_a = mew_data(content);
	add_data(stack, data_a);
	return (check);
}

int	check_space(char *data, t_data **stack_a)
{
	int		content;
	int		check;
	char	**str;
	int		i;

	i = 0;
	check = 0;
	str = NULL;
	content = 0;
	if (ft_isspace(data) > 0)
	{
		check = check_data(data);
		if (check == 0)
			str = ft_split(data, ' ');
		if (str == NULL || check == -1)
			return (check = -1, check);
		while (str[i] != NULL)
		{
			check = check_format(str[i], content, stack_a);
			if (check == -1)
				return (dest_free(str), check = -1, check);
			i++;
		}
	}
	return (dest_free(str), check);
}

int	check_init(char *data, t_data **stack_a)
{
	int		check;

	check = 0;
	check = ft_isspace(data);
	if (check == 1)
	{
		if (check == -1)
			return (check);
		check = check_space(data, stack_a);
		if (check == -1)
			return (check);
		check = 2;
	}
	if (check == 0)
	{
		if (data[0] == '\0')
			return (-1);
		check = single_data(data);
		if (check_overflow(data))
			check = -1;
	}
	return (check);
}
