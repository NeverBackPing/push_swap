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

data_s	*mew_data(int content)
{
	data_s	*node;

	node = malloc(sizeof(data_s));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	add_data(data_s **lst, data_s *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	data_delone(data_s *lst)
{
	if (lst == NULL)
		return ;
	free (lst);
}

void	merge(data_s *stack_a, data_s *stack_b)
{
	data_s	*a_head;
	data_s	*b_head;
	data_s	*a_next;
	data_s	*b_next;

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

void	data_clear(data_s **lst)
{
	data_s	*tmp;
	data_s	*tmp2;

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
