/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:43:46 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/04 19:09:26 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->length_a > 1)
	{	
		temp = stack->stack_a[stack->length_a - 1];
		i = stack->length_a - 1;
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = temp;
		write(1, "rra\n", 4);
		stack->iteration++;
	}
}

void	rrb(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->length_b > 1)
	{	
		temp = stack->stack_b[stack->length_b - 1];
		i = stack->length_b - 1;
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = temp;
		write(1, "rrb\n", 4);
		stack->iteration++;
	}
}

void	rrr(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->length_a > 1 && stack->length_b > 1)
	{	
		temp = stack->stack_a[stack->length_a - 1];
		i = stack->length_a - 1;
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = temp;
		temp = stack->stack_b[stack->length_b - 1];
		i = stack->length_b - 1;
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = temp;
		write(1, "rrr\n", 4);
		stack->iteration++;
	}
}
