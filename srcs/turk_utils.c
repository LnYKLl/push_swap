/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:00:00 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/12 10:00:00 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_values(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	get_chunk_size(int total_size)
{
	if (total_size <= 100)
		return (20);
	else if (total_size <= 500)
		return (40);
	else
		return (60);
}

int	get_median_pivot(t_stack *stack, int chunk_size)
{
	int	*sorted;
	int	i;
	int	pivot;

	sorted = (int *)malloc(sizeof(int) * chunk_size);
	if (!sorted)
		return (stack->arr[0]);
	i = 0;
	while (i < chunk_size)
	{
		sorted[i] = stack->arr[i];
		i++;
	}
	sort_array(sorted, chunk_size);
	pivot = sorted[chunk_size / 2];
	free(sorted);
	return (pivot);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_values(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}
