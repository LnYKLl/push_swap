/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:31:54 by lkiloul           #+#    #+#             */
/*   Updated: 2025/02/20 02:56:47 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);
    a.size = argc - 1;
    a.arr = (int *)malloc(sizeof(int) * a.size);
    b.size = 0;
    b.arr = (int *)malloc(sizeof(int) * a.size);
    if (!a.arr || !b.arr)
        return (0);
    for (int i = 0; i < a.size; i++)
        a.arr[i] = ft_atoi(argv[i + 1]);
    return (0);
}