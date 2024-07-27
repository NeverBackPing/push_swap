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

t_data	*small_index(t_data *stack)
{
	t_data	*small;
	t_data	*current;

	small = stack;
	current = stack;
	while (current != NULL)
	{
		if (current->position < small->position)
			small = current;
		current = current->next;
	}
	return (small);
}

int	great_value(t_data **stack)
{
	int		great;
	t_data	*tmp;

	great = 0;
	tmp = *stack;
	if (tmp)
		great = tmp->content;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (great < tmp->content && tmp != NULL)
			great = tmp->content;
		tmp = tmp->next;
	}
	return (great);
}

int	init_index(t_data **stack)
{
	int		pos;
	t_data	*current;
	t_data	*smallest;

	pos = 0;
	while (1)
	{
		current = *stack;
		smallest = NULL;
		while (current != NULL)
		{
			if (current->position == -1
				&& (smallest == NULL || current->content < smallest->content))
				smallest = current;
			current = current->next;
		}
		if (smallest == NULL)
			break ;
		smallest->position = pos++;
	}
	return (0);
}
