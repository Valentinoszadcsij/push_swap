/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:07:30 by voszadcs          #+#    #+#             */
/*   Updated: 2023/05/03 11:33:33 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != NULL)
	{	
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

void	check_dup(int *stack, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len)
	{
		if (stack[i] == stack[j] && i != j)
		{	
			free(stack);
			error(EXIT_DUP);
		}
		else
			j++;
		if (j == len)
		{	
			j = 0;
			i++;
		}
	}
}