/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:37:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/06/04 19:09:41 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int	quick_select(int *arr, int low, int high, int k)
{
	int	index;

	if (low <= high)
	{
		index = partition(arr, low, high);
		if (index == k)
			return (arr[index]);
		else if (index > k)
			return (quick_select(arr, low, index - 1, k));
		else
			return (quick_select(arr, index + 1, high, k));
	}
	return (-1);
}

int	find_mid(t_stack *s)
{
	int	*arr;
	int	i;
	int	med;

	i = 0;
	arr = malloc(sizeof(int) * (s->length_a));
	while (i < s->length_a)
	{
		arr[i] = s->stack_a[i];
		i++;
	}
	med = quick_select(arr, 0, s->length_a - 1, (s->length_a - 1) / 2);
	free(arr);
	return (med);
}
