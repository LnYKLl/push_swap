/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:00:00 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/12 10:00:00 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size <= 1)
		return (1);
	while (i < stack->size - 1)
	{
		if (stack->arr[i] > stack->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	handle_small_sort(t_stack *a)
{
	if (a->size == 2 && a->arr[0] > a->arr[1])
		swap_a(a);
}

void	sort_three(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	if (a->size < 3)
	{
		handle_small_sort(a);
		return ;
	}
	top = a->arr[0];
	middle = a->arr[1];
	bottom = a->arr[2];
	if (top > middle && middle < bottom && top < bottom)
		swap_a(a);
	else if (top > middle && middle > bottom)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		rotate_a(a);
	else if (top < middle && middle > bottom)
	{
		if (top < bottom)
			swap_a(a), rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}

void	turk_algorithm(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	total_size;
	
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_small_stack(a, b);
		return ;
	}
	normalize_stack(a);
	total_size = a->size;
	chunk_size = get_chunk_size(total_size);
	while (a->size > 3)
	{
		if (chunk_size > a->size)
			chunk_size = a->size;
		push_chunk_to_b(a, b, chunk_size);
	}
	sort_three(a);
	push_back_to_a(a, b);
}
