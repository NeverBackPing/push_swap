/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:54:58 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/25 02:47:31 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isspace(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = -1;
	while (str[i] != '\0')
	{
		if ((str[i] == 32) || (ft_isdigit(str) > -1))
		{
			check++;
		}
		i++;
	}
	return (check);
}
