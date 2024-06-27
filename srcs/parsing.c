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
	if (str[i] >= 48 && str[i] <= 57)
			NULL;
	else
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
		i++;
	}
	return (0);
}

int pars_array(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_digit_array(str))
			return (1);
		i++;
	}
	return (0);
}

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
				return (check = -1 ,check);
		}
		else
			return (check = -1 ,check);
	}
	else
		return (check = -1, check);
	return (check);
}

int	doublon(data_s **s, int c)
{
	data_s	*data_a;

	data_a = *s;
	while (data_a)
	{
		if (data_a->next == NULL)
				return (0);
		printf("loop: %d\n", (int)data_a->content );
		if ((int)data_a->content == c)
			return (1);
		data_a = data_a->next;
	}
	printf("%d\n", (int)data_a->content );
	return (0);
}

int	array_data(data_s **stack_a)
{
		data_s	*data_a;
		data_s	*check;

		check = NULL;
		data_a = *stack_a;
		while (data_a)
		{
			check = data_a;
			data_a = data_a->next;
			if (data_a == NULL)
				return (0);
			if (doublon(&check, data_a->content))
				return (1);
		}
		return (0);
}

/*int	array_data(data_s **stack_a)
{
		data_s	*data_a;
		data_s	*check;
		data_s	*head;

		data_a = NULL;
		check = NULL;
		head = *stack_a;
		while (head)
		{
			*data_a = *head->next;
			while (check)
			{
				if (data_a->content == (int)check->content)
				return (1);
				check = check->next;
			}
			head = head->next;
		}
		return (0);
}*/

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
			return (error_init(stack_a), 1);
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
	if (array_data(stack_a) == 0)
		return (0);
	else
		return (error_init(stack_a), 1);
}
