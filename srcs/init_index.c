/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:31:12 by sjossain          #+#    #+#             */
/*   Updated: 2024/07/23 20:00:30 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	j = 0;
	swapped = 0;
	while (i < size - 1)
	{
		j = 0;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

void	get_position(int *value, int count, t_data *current)
{
	int	i;

	i = 0;
	while (current)
	{
		i = 0;
		while (i < count)
		{
			if (value[i] == current->content)
			{
				current->position = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

int	init_index(t_data **stack)
{
	int		i;
	int		count;
	int		*value;
	t_data	*current;

	i = 0;
	current = *stack;
	count = lenstruct(stack);
	value = malloc(count * sizeof(int));
	if (value == NULL)
		return (1);
	while (current)
	{
		value[i++] = current->content;
		current = current->next;
	}
	bubble_sort(value, count);
	current = *stack;
	get_position(value, count, current);
	free(value);
	return (0);
}
