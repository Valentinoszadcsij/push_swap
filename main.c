/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:40:00 by voszadcs          #+#    #+#             */
/*   Updated: 2023/04/30 10:51:33 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	length;
	int	i;

	i = 0;
	length = 0;
	if (argc < 2)
		return (0);
	else
		stack_a = parser(argv, &length);
	while (i < length)
	{
		printf("%d\n", stack_a[i]);
		i++;
	}
	free(stack_a);

	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	func(argc, argv);
// 	system("leaks push_swap");
// }