/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:46:36 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/24 00:22:08 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
	{
		return (0);
	}
	return (1);
}
/*int	main(void)
{
	printf("%d\n", ft_isdigit('6'));
}*/
