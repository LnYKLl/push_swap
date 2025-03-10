/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:32:57 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/10 16:19:40 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
    int i;

    i = 0;
    if (src->size == 0)
        return ;
    dst->size++;
    int *new_arr = (int *)malloc(sizeof(int) * dst->size);
    if (!new_arr)
        return ;
    while (i < dst->size - 1)
    {
        new_arr[i] = dst->arr[i];
        i++;
    }
    new_arr[dst->size - 1] = src->arr[src->size - 1];
    free(dst->arr);
    dst->arr = new_arr;
    src->size--;
    new_arr = (int *)malloc(sizeof(int) * src->size);
    if (!new_arr && src->size > 0)
        return ;
    i = 0;
    while ( i < src->size)
    {
        new_arr[i] = src->arr[i];
        i++;
    }
    free(src->arr);
    src->arr = new_arr;
}

void    push_a(t_stack *a, t_stack *b)
{
    push(b, a);
    ft_printf("pa\n");
}

void    push_b(t_stack *a, t_stack *b)
{
    push(a, b);
    ft_printf("pb\n");
}
