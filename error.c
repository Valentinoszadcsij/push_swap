/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:33:12 by voszadcs          #+#    #+#             */
/*   Updated: 2023/05/02 14:52:49 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int errnum)
{
	if (errnum == EXIT_NON_INT)
	{
		write(2, "Error: non-digit character passed as a parameter.\n", 51);
		exit (EXIT_FAILURE);
	}
	if (errnum == EXIT_OVER_MAX_INT)
	{
		write(2, "Error: a number over INT_MAX value passed.\n", 43);
		exit (EXIT_FAILURE);
	}
	if (errnum == EXIT_DUP)
	{
		write(2, "Error: duplicate input numbers found.\n", 51);
		exit (EXIT_FAILURE);
	}
}