/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:53:41 by utente            #+#    #+#             */
/*   Updated: 2025/03/19 02:21:42 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	int	len;

	len = stack_len(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node	**a, int checker)
{
	swap(a);
	if (!checker)
		if (write(1, "sa\n", 3) == -1)
			exit(EXIT_FAILURE);
}

void	sb(t_stack_node **b, int checker)
{
	swap(b);
	if (!checker)
		if (write(1, "sb\n", 3) == -1)
			exit(EXIT_FAILURE);
}

void	ss(t_stack_node **a, t_stack_node **b, int checker)
{
	swap(a);
	swap(b);
	if (!checker)
		if (write(1, "ss\n", 3) == -1)
			exit(EXIT_FAILURE);
}
