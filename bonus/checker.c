/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:33:25 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/08 14:54:41 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	// int		i;
	t_stack	stack;

	// i = 0;
	if (argc < 2)
		return (0);
	else
	{
		stack.length_a = 0;
		stack.stack_a = parser(argv, &stack.length_a);
		stack.length_b = 0;
		stack.stack_b = malloc(sizeof(int) * stack.length_a);
		stack.iteration = 0;
	}
	// while (i < stack.length_a)
	// {
	// 	printf("a: %d\n", stack.stack_a[i]);
	// 	i++;
	// }
	return (0);
}