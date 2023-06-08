/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:07:30 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/04 18:55:43 by voszadcs         ###   ########.fr       */
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

void	init_t_calc(t_calc *calc)
{
	calc->rot_a = INT_MAX;
	calc->rot_b = 0;
	calc->r_rot_a = INT_MAX;
	calc->r_rot_b = 0;
	calc->best_cur = 0;
	calc->cur = 0;
	calc->iter_cur = 0;
	calc->iter_prev = INT_MAX;
}

int	find_min(t_stack *s)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < s->length_a - 1)
	{
		if (s->stack_a[i] >= s->stack_a[i + 1]
			&& s->stack_a[index] >= s->stack_a[i + 1])
			index = i + 1;
		i++;
	}
	return (s->stack_a[index]);
}

int	find_max(t_stack *s)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < s->length_a - 1)
	{
		if (s->stack_a[i] <= s->stack_a[i + 1]
			&& s->stack_a[index] <= s->stack_a[i + 1])
			index = i + 1;
		i++;
	}
	return (s->stack_a[index]);
}
