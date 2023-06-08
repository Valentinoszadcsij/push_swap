/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:10:37 by voszadcs          #+#    #+#             */
/*   Updated: 2023/05/23 23:49:07 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	int	i;

	i = stack->length_a;
	if (stack->length_b > 0)
	{	
		stack->length_a += 1;
		while (i > 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
		stack->stack_a[0] = stack->stack_b[0];
		stack->length_b -= 1;
		i = 0;
		while (i < stack->length_b)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		write(1, "pa\n", 3);
		stack->iteration++;
	}
}

void	pb(t_stack *stack)
{
	int	i;

	i = stack->length_b;
	if (stack->length_a > 0)
	{	
		stack->length_b += 1;
		while (i > 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
		stack->stack_b[0] = stack->stack_a[0];
		stack->length_a -= 1;
		i = 0;
		while (i < stack->length_a)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		write(1, "pb\n", 3);
		stack->iteration++;
	}
}
