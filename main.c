/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:40:00 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/04 20:04:40 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stack, char *argv[])
{
	stack->length_a = 0;
	stack->stack_a = parser(argv, &stack->length_a);
	stack->length_b = 0;
	stack->stack_b = malloc(sizeof(int) * stack->length_a);
	stack->iteration = 0;
}

int	main(int argc, char **argv)
{
	// int	i = 0;
	t_stack stack;
	if (argc < 2)
		return (0);
	else
		stack_init(&stack, argv);
	push_swap(&stack);
	// while (i < stack.length_a)
	// {
	// 	printf("a: %d\n", stack.stack_a[i]);
	// 	i++;
	// }
	// i = 0;
	// while (i < stack.length_b)
	// {
	// 	printf("b: %d\n", stack.stack_b[i]);
	// 	i++;
	// }
	// printf("Total: %d", stack.iteration);
	free(stack.stack_a);
	free(stack.stack_b);

	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	func(argc, argv);
// 	system("leaks push_swap");
// }