/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:46:36 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/26 14:39:54 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	check(int first, int second, int digit)
{
	if (first == 32)
	{
		if (second == 45 || second == 43)
			return (1);
	}
	if ((second == 45 || second == 43) && (digit >= 48 && digit <= 57))
		return (1);
	else
		return (0);
}

int check_signe(char *str)
{
	int		i;
	//int		check;

	i = 0;
	//check = 0;
	while (str[i] != '\0')
	{
		if ((str[i]== 45 || str[i] == 43))
		{
			if (str[i - 1] == 32 || i == 0)
				NULL;
			else
				return (1);
			i++;
			if ((str[i] >= 48 && str[i] <= 57))
			{
				if(check(str[i - 2], str[i - 1], str[i]))
					return (0);
				else
					return (1);
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}
int	good_digit(int c)
{
	int		check;

	check = 0;
	if (c == 32)
		check++;
	if ((c >= 48 && c<= 57))
		check++;
	if (c == 45 || c == 43)
			check++;
	return (check);
}
int	check_digit(int c, char *str)
{
	int		check;

	check = 0;
	if (c == 32)
		check++;
	check = good_digit(c);
	if (check > 0)
		check++;
	else
		return (check = -1, check);
	check = check_signe(str);
	if (check == 0)
		check++;
	else
	{
		check = -1;
		return (check);
	}
	if (check == 0)
		check = -1;
	return (check);
}

int	ft_isdigit(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		check = check_digit(str[i], str);
		if (check == -1)
			return (check = -1, check);
		i++;
	}
	return (check);
}
/*int	main(void)
{
	printf("%d\n", ft_isdigit('6'));
}*/
