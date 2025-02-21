/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:33:43 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/20 02:55:26 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
    int tmp;

    if (stack->size < 2)
        return ;
    tmp = stack->arr[stack->size - 1];
    stack->arr[stack->size - 1] = stack->arr[stack->size - 2];
    stack->arr[stack->size - 2] = tmp;
}

void    swap_a(t_stack *a)
{
    swap(a);
    ft_printf("sa\n");
}

void    swap_b(t_stack *b)
{
    swap(b);
    ft_printf("sb\n");
}

void swap_both(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}