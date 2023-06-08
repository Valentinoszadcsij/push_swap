/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:52:47 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/04 19:51:05 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->length_a == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			sa(stack);
	}
	else
	{
		if (stack->stack_a[0] < stack->stack_a[1])
		{	
			if (stack->stack_a[1] > stack->stack_a[2]
				&& stack->stack_a[2] > stack->stack_a[0])
				sa(stack);
		}
		else if (stack->stack_a[0] > stack->stack_a[1]
			&& stack->stack_a[0] < stack->stack_a[2])
			sa(stack);
		else if (stack->stack_a[0] > stack->stack_a[1]
			&& stack->stack_a[1] > stack->stack_a[2])
			sa(stack);
	}
}

void	sort_end(t_stack *stack)
{	
	int	min;
	int	i;

	i = 0;
	min = find_min(stack);
	while (i < stack->length_a)
	{
		if (stack->stack_a[i] == min)
			break ;
		i++;
	}
	if (i <= stack->length_a / 2)
	{	
		while (i-- > 0)
			ra(stack);
	}
	else
	{	
		while (i++ < stack->length_a)
			rra(stack);
	}
}

void	divide_stacks(t_stack *stack)
{
	int	min;
	int	max;
	int	mid;

	mid = find_mid(stack);
	min = find_min(stack);
	max = find_max(stack);
	while (stack->length_a != 3)
	{	
		if (stack->stack_a[0] != min && stack->stack_a[0] != max)
		{
			if (stack->stack_a[0] < mid)
				pb(stack);
			else
			{
				pb(stack);
				rb(stack);
			}
		}	
		else
			ra(stack);
	}
	sort_3(stack);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while(i < s->length_a - 1)
	{
		if(s->stack_a[i] > s->stack_a[i + 1])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}