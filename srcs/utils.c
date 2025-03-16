/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:00:00 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/12 10:00:00 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	if (stack->size == 0)
		return (0);
	min = stack->arr[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->arr[i] < min)
			min = stack->arr[i];
		i++;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	i;
	int	max;

	if (stack->size == 0)
		return (0);
	max = stack->arr[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}

int	find_position(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	swap_values(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	normalize_stack(t_stack *a)
{
	int		*sorted;
	int		*indices;
	int		i;
	int		j;

	sorted = (int *)malloc(sizeof(int) * a->size);
	indices = (int *)malloc(sizeof(int) * a->size);
	if (!sorted || !indices)
		return ;
	i = 0;
	while (i < a->size)
	{
		sorted[i] = a->arr[i];
		i++;
	}
	i = 0;
	while (i < a->size - 1)
	{
		j = 0;
		while (j < a->size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
				swap_values(&sorted[j], &sorted[j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->arr[i] == sorted[j])
			{
				indices[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		a->arr[i] = indices[i];
		i++;
	}
	free(sorted);
	free(indices);
}
