/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:53:16 by sjossain          #+#    #+#             */
/*   Updated: 2024/07/11 14:21:16 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

size_t	len_array(int tab)
{
	size_t	i;
	size_t	n;
	size_t	len;

	i = 0;
	len = 0;
	n = sizeof(tab) / sizeof(int);
	printf("value n: %zu \n", n);
	while (i++ < n)
	{
		printf("value i: %zu \n", i);
		len++;
	}
	return (len);
}

void	swap_array(int* a, int* b)
{
	int	tmp;

	tmp	= *a;
	*a = *b;
	*b = tmp;
}

/*int	*array(t_data **stack)
{
	int		*tab;
	int		array[lenstruct(stack)];
	int		len;
	t_data	*tmp;
	size_t	i;

	i = 0;
	tmp = *stack;
	len = lenstruct(stack);
	tab = array;
	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}*/

void printArray(int *arr, int size)
{
	int	i;

	i = 0;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int	array_index(int *tab, int len)
{
	int		index;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	index = 0;
	printArray(tab, len);
	if (size % 2 == 0)
	{
		size = (len / 2) + 1;
		while (i++ < size)
			index = tab[i];
	}
	else
	{
		size = (((len - 1) / 2) + 1);
		while (i++ < size)
			index = tab[i];
	}
	return(index);
}

int	array(t_data **stack)
{
	int		array[0];
	int		*tab;
	int		len;
	t_data	*tmp;
	size_t	i;

	i = 0;
	tmp = *stack;
	len = lenstruct(stack);
	array[len];
	tab = &array;
	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (sort_array(array, tab));
}

int	sort_array(int tab, int *array)
{
	int		*array;
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	min_indx;

	i = 0;
	j = 0;
	min_indx = 0;
	size = len_array(tab);
	array = tab;
	while (i < size - 1)
	{
		min_indx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_indx])
				min_indx = j;
			j++;
		}
		swap_array(&array[min_indx], &array[i]);
		i++;
	}
	return (array_index(array, size));
}

