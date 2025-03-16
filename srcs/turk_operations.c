/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:00:00 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/12 10:00:00 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize_b_stack(t_stack *b)
{
	if (b->size > 1 && b->arr[0] < b->arr[1])
		rotate_b(b);
}

static void	handle_rotation(t_stack *a, int *rotated, int chunk_size)
{
	int	i;

	if (chunk_size <= 5 || *rotated <= chunk_size / 2)
		return ;
	i = 0;
	while (i < *rotated % a->size)
	{
		reverse_rotate_a(a);
		i++;
	}
}

static void	process_chunk_element(t_stack *a, t_stack *b, int pivot, 
								int *pushed, int *rotated)
{
	if (a->arr[0] < pivot)
	{
		push_b(a, b);
		(*pushed)++;
		optimize_b_stack(b);
	}
	else
	{
		rotate_a(a);
		(*rotated)++;
	}
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;
	int	pivot;
	int	pushed;
	int	rotated;

	if (a->size <= 3)
	{
		sort_three(a);
		return ;
	}
	pivot = get_median_pivot(a, chunk_size);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (pushed < chunk_size / 2 && i < chunk_size * 2)
	{
		process_chunk_element(a, b, pivot, &pushed, &rotated);
		i++;
	}
	handle_rotation(a, &rotated, chunk_size);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = find_position(b, find_max(b));
		if (max_pos <= b->size / 2)
		{
			while (b->arr[0] != find_max(b))
				rotate_b(b);
		}
		else
		{
			while (b->arr[0] != find_max(b))
				reverse_rotate_b(b);
		}
		push_a(a, b);
	}
}
