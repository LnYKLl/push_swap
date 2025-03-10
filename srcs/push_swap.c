/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:31:54 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/10 17:35:42 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    int i;
    if  (check_int(argc, argv) == 0);
        return (0);
    if (argc < 2)
        return (0);
    a.size = argc - 1;
    a.arr = (int *)malloc(sizeof(int) * a.size);
    if (!a.arr)
        return (0);
    i = 0;
    while (i < a.size)
    {
        a.arr[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    b.size = 0;
    b.arr = NULL;
    i = 0;
    while (i < a.size)
    {
        ft_printf("%d\n", a.arr[i]);
        i++;
    }
    rotate_a(&a);
    ft_printf(" stack A\n");
    i = 0;
    while (i < a.size)
    {
        ft_printf("%d\n", a.arr[i]);
        i++;
    }

    i = 0;

    while (i < b.size)
    {
        ft_printf("%d\n", b.arr[i]);
        i++;
    }
    return (0);
}

int check_int(int argc, char **argv)
{
    int i;

    i = 0;

    while (i < argc)
    {
        if (argv[i] >= 0 && argv[i] <= 9)
            i++;
        else
        ft_printf("Error\n input is not a number\n");
            return (0);
    }
    return (1);
}