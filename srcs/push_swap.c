/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:31:54 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/11 14:54:21 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack_a(t_stack *a, int argc, char **argv)
{
	int	i;

	a->size = argc - 1;
	a->arr = (int *)malloc(sizeof(int) * a->size);
	if (!a->arr)
		return ;
	i = 0;
	while (i < a->size)
	{
		a->arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	if (check_int(argc, argv) == 0)
		return (0);
	init_stack_a(&a, argc, argv);
	if (!a.arr)
		return (0);
	b.size = 0;
	b.arr = NULL;
	if (!is_sorted(&a))
		turk_algorithm(&a, &b);
	if (a.arr)
		free(a.arr);
	if (b.arr)
		free(b.arr);
	return (0);
}

int	check_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}