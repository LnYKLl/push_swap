/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:39:32 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/17 15:26:53 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Rotate the stack (shift up all elements by 1, the first becomes the last)
 * Returns 1 if successful, 0 if stack has less than 2 elements
 */
static int	rotate(t_stack *stack)
{
	int	first;
	int	i;

	if (stack->size < 2)
		return (0);
	first = stack->arr[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->size - 1] = first;
	return (1);
}

/*
 * Rotate stack a
 * Print "ra" if successful
 */
void	ra(t_stack *a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

/*
 * Rotate stack b
 * Print "rb" if successful
 */
void	rb(t_stack *b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

/*
 * Rotate both stack a and stack b
 * Print "rr" if both rotations are successful
 */
void	rr(t_stack *a, t_stack *b)
{
	int	success_a;
	int	success_b;

	success_a = rotate(a);
	success_b = rotate(b);
	if (success_a && success_b)
		write(1, "rr\n", 3);
	else
	{
		if (success_a)
			write(1, "ra\n", 3);
		if (success_b)
			write(1, "rb\n", 3);
	}
}