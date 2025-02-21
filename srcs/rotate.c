/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:35:05 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/20 02:39:20 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *stack)
{
    {
        if (stack == NULL || stack->size < 2)
            return;

        int first = stack->arr[0];
        for (int i = 0; i < stack->size - 1; i++)
        {
            stack->arr[i] = stack->arr[i + 1];
        }
        stack->arr[stack->size - 1] = first;
    }
}

void    rotate_a(t_stack *a)
{
    rotate(a);
    ft_printf("ra\n");
}

void    rotate_b(t_stack *b)
{
    rotate(b);
    ft_printf("rb\n");
}
void rotate_both(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}