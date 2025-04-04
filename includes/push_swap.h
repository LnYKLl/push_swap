/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:42:44 by utente            #+#    #+#             */
/*   Updated: 2025/03/29 12:22:56 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

char					**ft_split(char const *s, char c);

void					free_matrix(char **argv);
void					error_free(t_stack_node **a, char **argv,
							int flag_argc_2);
void					free_stack(t_stack_node **stack);
int						error_repetition(t_stack_node *a, int nbr);
int						error_syntax(char *str_nbr);

void					stack_init(t_stack_node **a, char **argv,
							int flag_argc_2);
void					init_nodes(t_stack_node *a, t_stack_node *b);
void					set_current_position(t_stack_node *stack);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);

void					append_node(t_stack_node **stack, int nbr);
t_stack_node			*find_last_node(t_stack_node *head);
t_stack_node			*find_smallest(t_stack_node *stack);
t_stack_node			*return_cheapest(t_stack_node *stack);
int						stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
void					finish_rotation(t_stack_node **s, t_stack_node *n,
							char c);

void					tiny_sort(t_stack_node **a);
void					handle_five(t_stack_node **a, t_stack_node **b);
void					push_swap(t_stack_node **a, t_stack_node **b);

void					sa(t_stack_node **a, int checker);
void					sb(t_stack_node **b, int checker);
void					ss(t_stack_node **a, t_stack_node **b, int checker);
void					ra(t_stack_node **a, int checker);
void					rb(t_stack_node **b, int checker);
void					rr(t_stack_node **a, t_stack_node **b, int checker);
void					rra(t_stack_node **a, int checker);
void					rrb(t_stack_node **b, int checker);
void					rrr(t_stack_node **a, t_stack_node **b, int checker);
void					pa(t_stack_node **a, t_stack_node **b, int checker);
void					pb(t_stack_node **b, t_stack_node **a, int checker);

#endif
