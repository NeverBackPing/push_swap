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

int	check_data(char *data)
{
	int	check;

	check = 0;
	if (ft_isdigit(data) > -1)
	{
		if (ft_signe(data) < 1)
			NULL ;
		else
		{
			return (check = -1 ,check);
		}
	}
	else
	{
			return (check = -1, check);
	}
	return (check);
}

int	check_space(char *data, data_s **stack_a)
{
	data_s	*data_a;
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
			check = check_data(str[i]);
			if (check == -1)
				return (dest_free(str), check);
			content = ft_atol(str[i]);
			data_a = mew_data(content);
			add_data(stack_a, data_a);
			i++;
		}
	}
	return (dest_free(str), check);
}

int	check_init(char *data, data_s **stack_a)
{
	int		check;
	int		process;

	check = 0;
	process = 1;
	check = ft_isspace(data);
	if ( check == 0)
	{
		process = 0;
		check = check_data(data);
	}
	if (process)
	{
		if (check == -1)
			return (check);
		check = check_space(data, stack_a);
		if (check == -1)
			return (check);
		check = 2;
	}
	if (check_overflow(data))
	{
		check = -1;
	}
	return (check);
}
