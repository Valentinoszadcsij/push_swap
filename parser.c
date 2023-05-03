/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:54:53 by voszadcs          #+#    #+#             */
/*   Updated: 2023/05/02 14:48:24 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *str)
{
	size_t	length;

	length = ft_strlen(str);
	if (length >= 10 && length <= 11)
	{
		if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
			return (-1);
		else
			return (0);
	}
	else if (length > 11)
		return (-1);
	return (0);
}

//format input string digits
//to int and push them into stack_a
static void	push_int(int *stack, char *array, int *k)
{
	int		j;
	char	**temp;

	j = 0;
	temp = ft_split(array, ' ');
	while (temp[j] != NULL)
	{
		if (is_int(temp[j]) == -1)
		{	
			free_free(temp);
			free(stack);
			error(EXIT_OVER_MAX_INT);
		}
		stack[*k] = ft_atoi(temp[j]);
		j++;
		*k += 1;
	}
	j = 0;
	while (temp[j] != NULL)
	{	
		free(temp[j]);
		temp[j] = NULL;
		j++;
	}
	free(temp);
}

static int	check_minus(char *array, int i)
{
	if (array[i] == '-' && ft_isdigit(array[i + 1]) == 1
		&& array[i - 1] == ' ' && array[i + 1] != '\0')
		return (1);
	else if (array[0] == '-' && i == 0
		&& array[i + 1] != '\0')
		return (1);
	else
		return (0);
}

// count number of integers
static int	count_int(char *array)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (array[j] != '\0')
	{
		if (array[j] == ' ')
			j++;
		else if (ft_isdigit(array[j]) == 1 || check_minus(array, j) == 1)
		{
			if (array[j + 1] == ' ' || array[j + 1] == '\0')
			{
				count++;
				j++;
			}
			else
				j++;
		}
		else
			error(EXIT_NON_INT);
	}
	return (count);
}

int	*parser(char **argv, int *length)
{
	int			i;
	int			*stack_a;
	static int	k;

	i = 0;
	k = 0;
	while (argv[++i] != NULL)
		*length += count_int(argv[i]);
	i = 0;
	stack_a = malloc(sizeof(int) * (*length));
	while (argv[++i] != NULL)
		push_int(stack_a, argv[i], &k);
	return (check_dup(stack_a, *length), stack_a);
}
