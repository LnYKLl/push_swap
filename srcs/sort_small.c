/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:00:00 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/12 10:00:00 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	min_pos;

	while (a->size > 3)
	{
		min = find_min(a);
		min_pos = find_position(a, min);
		if (min_pos <= a->size / 2)
		{
			while (a->arr[0] != min)
				rotate_a(a);
		}
		else
		{
			while (a->arr[0] != min)
				reverse_rotate_a(a);
		}
		push_b(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		push_a(a, b);
}

void	sort_small_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		sort_three(a);
	else
		sort_five(a, b);
}
