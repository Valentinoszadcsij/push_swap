/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:22:19 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/26 18:42:23 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
long	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		else if ((str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		i++;
	}
	while (str[i] != 0 && ft_isdigit(str[i]) == 1)
	{
		res = res * 10 + (str[i] % 48);
		i++;
	}
	return (res * sign);
}

// #include <stdlib.h>
// int main()
// {	
// 	printf("%i", ft_atoi("546:5"));
// 	return (0);
// }