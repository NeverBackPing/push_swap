/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 15:20:55 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

t_data	*mew_data(int content)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	add_data(t_data **lst, t_data *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	data_delone(t_data *lst)
{
	if (lst == NULL)
		return ;
	free (lst);
}

void	merge(t_data *stack_a, t_data *stack_b)
{
	t_data	*a_head;
	t_data	*b_head;
	t_data	*a_next;
	t_data	*b_next;

	a_head = stack_a;
	b_head = stack_b;
	while (a_head != NULL && b_head != NULL)
	{
		a_next = a_head->next;
		b_next = b_head->next;
		b_head->next = a_next;
		a_head->next = b_head;
		a_head = a_next;
		b_head = b_next;
	}
	stack_b = b_head;
}

void	data_clear(t_data **lst)
{
	t_data	*tmp;
	t_data	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		data_delone(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
