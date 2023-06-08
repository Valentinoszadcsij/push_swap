/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:14:50 by voszadcs          #+#    #+#             */
/*   Updated: 2023/05/27 16:22:57 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->length_a > 1)
	{	
		temp = stack->stack_a[0];
		i = 0;
		while (i < stack->length_a - 1)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->stack_a[stack->length_a - 1] = temp;
		write(1, "ra\n", 3);
		stack->iteration++;
	}
}

void	rb(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->length_b > 1)
	{	
		temp = stack->stack_b[0];
		i = 0;
		while (i < stack->length_b - 1)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->stack_b[stack->length_b - 1] = temp;
		write(1, "rb\n", 3);
		stack->iteration++;
	}
}

void	rr(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->length_a > 1 && stack->length_b > 1)
	{	
		temp = stack->stack_a[0];
		i = 0;
		while (i < stack->length_a - 1)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->stack_a[stack->length_a - 1] = temp;
		temp = stack->stack_b[0];
		i = 0;
		while (i < stack->length_b - 1)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->stack_b[stack->length_b - 1] = temp;
		write(1, "rr\n", 3);
		stack->iteration++;
	}
}
