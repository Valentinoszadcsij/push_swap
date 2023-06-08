/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:43:51 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/04 19:52:45 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(t_calc *c)
{
	c->iter_cur = c->iter_prev;
	if (c->rot_a <= c->rot_b && c->rot_b < c->iter_cur
		&& set_flag(&c->op_flag, 0) == 0)
		c->iter_cur = c->rot_b;
	else if (c->rot_a >= c->rot_b && c->rot_a < c->iter_cur
		&& set_flag(&c->op_flag, 0) == 0)
		c->iter_cur = c->rot_a;
	if (c->rot_a + c->r_rot_b < c->iter_cur
		&& set_flag(&c->op_flag, 1) == 1)
		c->iter_cur = c->rot_a + c->r_rot_b;
	if (c->r_rot_a + c->rot_b < c->iter_cur
		&& set_flag(&c->op_flag, 2) == 2)
		c->iter_cur = c->r_rot_a + c->rot_b;
	if (c->r_rot_a <= c->r_rot_b && c->r_rot_b < c->iter_cur
		&& set_flag(&c->op_flag, 3) == 3)
		c->iter_cur = c->r_rot_b;
	else if (c->r_rot_a >= c->r_rot_b && c->r_rot_a < c->iter_cur
		&& set_flag(&c->op_flag, 3) == 3)
		c->iter_cur = c->r_rot_a;
	if (c->iter_prev > c->iter_cur)
		return (c->iter_prev = c->iter_cur, 1);
	else
		return (0);
}

void	calc_a(t_stack *s, t_calc *c)
{
	int	i;

	i = 0;
	while (i < s->length_a - 1)
	{
		if (s->stack_b[c->cur] < s->stack_a[0]
			&& s->stack_b[c->cur] > s->stack_a[s->length_a - 1])
		{
			c->rot_a = 0;
			c->r_rot_a = s->length_a - 1;
		}
		else if (s->stack_b[c->cur] > s->stack_a[i]
			&& s->stack_b[c->cur] < s->stack_a[i + 1])
		{
			c->rot_a = i + 1;
			c->r_rot_a = s->length_a - i - 1;
		}
		i++;
	}
}

void	exec(t_stack *s, t_calc *c)
{
	if (c->op_flag == 0)
		ra_rb(s, c);
	else if (c->op_flag == 1)
		ra_rrb(s, c);
	else if (c->op_flag == 2)
		rra_rb(s, c);
	else if (c->op_flag == 3)
		rra_rrb(s, c);
}

void	calc_opt(t_stack *stack)
{
	int		i;
	t_calc	calc;

	i = 0;
	init_t_calc(&calc);
	while (i < stack->length_b)
	{	
		calc.cur = i;
		calc.rot_b = i;
		calc.r_rot_b = stack->length_b - i;
		calc_a(stack, &calc);
		if (compare(&calc) == 1)
			calc.best_cur = i;
		i++;
	}
	calc.cur = calc.best_cur;
	calc_a(stack, &calc);
	calc.rot_b = calc.cur;
	calc.r_rot_b = stack->length_b - calc.cur;
	exec(stack, &calc);
}

void	push_swap(t_stack *stack)
{
	if (stack->length_a < 2)
		return ;
	else if (stack->length_a <= 3)
	{	
		sort_3(stack);
		while (stack->length_a == 3 && stack->stack_a[0] > stack->stack_a[2])
			ra(stack);
	}
	else
	{
		if (is_sorted(stack) == 0)
			return ;
		divide_stacks(stack);
		while (stack->length_b != 0)
			calc_opt(stack);
	}
	sort_end(stack);
}
