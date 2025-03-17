/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*   Created: 2025/02/20 02:39:53 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/17 15:27:30 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Reverse rotate the stack (shift down all elements by 1, the last becomes first)
 * Returns 1 if successful, 0 if stack has less than 2 elements
 */
static int	reverse_rotate(t_stack *stack)
{
	int	last;
	int	i;

	if (stack->size < 2)
		return (0);
	last = stack->arr[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = last;
	return (1);
}

/*
 * Reverse rotate stack a
 * Print "rra" if successful
 */
void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		write(1, "rra\n", 4);
}

/*
 * Reverse rotate stack b
 * Print "rrb" if successful
 */
void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		write(1, "rrb\n", 4);
}

/*
 * Reverse rotate both stack a and stack b
 * Print "rrr" if both reverse rotations are successful
 */
void	rrr(t_stack *a, t_stack *b)
{
	int	success_a;
	int	success_b;

	success_a = reverse_rotate(a);
	success_b = reverse_rotate(b);
	if (success_a && success_b)
		write(1, "rrr\n", 4);
	else
	{
		if (success_a)
			write(1, "rra\n", 4);
		if (success_b)
			write(1, "rrb\n", 4);
	}
}