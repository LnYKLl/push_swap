/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:29:20 by lkiloul           #+#    #+#             */
/*   Updated: 2025/03/11 14:22:35 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/includes/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
}		t_stack;

int		check_int(int argc, char **argv);
int		check_duplicate(t_stack *stack);
void	exit_error(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
void	init_stacks(t_stack *a, t_stack *b, int argc, char **argv);

void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);

void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_both(t_stack *a, t_stack *b);

void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);

void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);
void	reverse_rotate_both(t_stack *a, t_stack *b);

void	turk_algorithm(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
void	sort_three(t_stack *a);
void	sort_small_stack(t_stack *a, t_stack *b);

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_position(t_stack *stack, int value);
void	normalize_stack(t_stack *a);

int		get_chunk_size(int total_size);
int		get_median_pivot(t_stack *stack, int chunk_size);
void	sort_array(int *arr, int size);
void	swap_values(int *a, int *b);
void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk_size);
void	push_back_to_a(t_stack *a, t_stack *b);

#endif