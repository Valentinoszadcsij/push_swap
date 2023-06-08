/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:31:30 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/04 18:55:50 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_stack *s, t_calc *c)
{
	while (c->rot_a > 0 && c->rot_b > 0)
	{	
		rr(s);
		c->rot_a--;
		c->rot_b--;
	}
	while (c->rot_a > 0)
	{
		ra(s);
		c->rot_a--;
	}
	while (c->rot_b > 0)
	{
		rb(s);
		c->rot_b--;
	}
	pa(s);
}

void	ra_rrb(t_stack *s, t_calc *c)
{
	while (c->rot_a > 0)
	{
		ra(s);
		c->rot_a--;
	}
	while (c->r_rot_b > 0)
	{
		rrb(s);
		c->r_rot_b--;
	}
	pa(s);
}

void	rra_rb(t_stack *s, t_calc *c)
{
	while (c->r_rot_a > 0)
	{
		rra(s);
		c->r_rot_a--;
	}
	while (c->rot_b > 0)
	{
		rb(s);
		c->rot_b--;
	}
	pa(s);
}

void	rra_rrb(t_stack *s, t_calc *c)
{
	while (c->r_rot_a > 0 && c->r_rot_b > 0)
	{	
		rrr(s);
		c->r_rot_a--;
		c->r_rot_b--;
	}
	while (c->r_rot_a > 0)
	{
		rra(s);
		c->r_rot_a--;
	}
	while (c->r_rot_b > 0)
	{
		rrb(s);
		c->r_rot_b--;
	}
	pa(s);
}

int	set_flag(int *flag, int value)
{
	*flag = value;
	return (value);
}
