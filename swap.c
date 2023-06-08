/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:52:18 by voszadcs          #+#    #+#             */
/*   Updated: 2023/05/23 21:02:20 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->length_a > 1)
	{
		temp = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = temp;
		write(1, "sa\n", 3);
		stack->iteration++;
	}
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->length_b > 1)
	{
		temp = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = temp;
		write(1, "sb\n", 3);
		stack->iteration++;
	}
}

void	ss(t_stack *stack)
{
	int	temp;

	if (stack->length_a > 1)
	{
		temp = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = temp;
	}
	if (stack->length_b > 1)
	{
		temp = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = temp;
	}
	write(1, "ss\n", 3);
	stack->iteration++;
}
