/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:51:29 by voszadcs          #+#    #+#             */
/*   Updated: 2023/05/02 14:47:15 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_NON_INT 1
# define EXIT_OVER_MAX_INT 2
# define EXIT_DUP 3
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# include "lib/libft/libft.h"

int		*parser(char **argv, int *length);
void	error(int errnum);
void	free_free(char **str);
void	check_dup(int *stack, int len);

#endif