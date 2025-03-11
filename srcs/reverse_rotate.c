/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:56:42 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/11 15:01:47 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

void reverse_rotate(t_stack *stack)
{
    int i;
    int last;

    i = stack->size - 1;
    if (stack == NULL || stack->size < 2)
        return ;
    last = stack->arr[stack->size - 1];
    while (i > 0)
    {
        stack->arr[i] = stack->arr[i - 1];
        i--;
    }
    stack->arr[0] = last;
}

void reverse_rotate_a(t_stack *a)
{
    reverse_rotate(a);
    ft_printf("rra\n");
}

void reverse_rotate_b(t_stack *b)
{
    reverse_rotate(b);
    ft_printf("rrb\n");
}

void reverse_rotate_both(t_stack  *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rrr\n");
}