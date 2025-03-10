/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:35:05 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/10 16:33:54 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	i;
	int	first;

	i = 0;
	if (stack == NULL || stack->size < 2)
		return ;
	first = stack->arr[0];
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
        i++;
	}
	stack->arr[stack->size - 1] = first;
}

void	rotate_a(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}
void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}