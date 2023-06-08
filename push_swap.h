/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:51:29 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/08 16:20:32 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_NON_INT 1
# define EXIT_OVER_MAX_INT 2
# define EXIT_DUP 3
# define RA_RB 0;
# define RA_RRB 1;
# define RRA_RB 2;
# define RRA_RRB 3;
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "lib/libft/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	length_a;
	int	length_b;
	int	iteration;
}	t_stack;

typedef struct s_calc
{
	int	rot_a;
	int	r_rot_a;
	int	rot_b;
	int	r_rot_b;
	int	best_cur;
	int	cur;
	int	iter_cur;
	int	iter_prev;
	int	op_flag;
}	t_calc;

int		*parser(char **argv, int *length);
void	error(int errnum);
void	free_free(char **str);
void	check_dup(int *stack, int len);
void	sort_3(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
void	push_swap(t_stack *stack);
void	init_t_calc(t_calc *calc);
int		set_flag(int *flag, int value);
void	ra_rb(t_stack *s, t_calc *c);
void	ra_rrb(t_stack *s, t_calc *c);
void	rra_rb(t_stack *s, t_calc *c);
void	rra_rrb(t_stack *s, t_calc *c);
int		find_min(t_stack *s);
int		find_max(t_stack *s);
int		find_mid(t_stack *s);
void	sort_end(t_stack *stack);
void	divide_stacks(t_stack *stack);
int		is_sorted(t_stack *s);

#endif
