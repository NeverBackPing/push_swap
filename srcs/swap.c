/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/21 16:12:35 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str = ft_itoa(150000);
	ft_printf("%s\n", str);
	ft_printf("%d\n", ft_atoi("55"));
	ft_printf("%s\n", ft_strchr("hello", 'l'));
	return (0);
}