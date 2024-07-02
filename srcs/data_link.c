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
	node->prev = NULL;
	return (node);
}

void	add_data(t_data **lst, t_data *new)
{
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
	else
		new->next = *lst;
}

void	data_delone(t_data *lst)
{
	if (lst == NULL)
		return ;
	free (lst);
}

t_data	*last(t_data **lst)
{
	while (*lst)
	{
		if ((*lst)->next == NULL)
			return (*lst);
		lst = &(*lst)->next;
	}
	return (NULL);
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
