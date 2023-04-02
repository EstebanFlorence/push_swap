/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:14:19 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/02 01:36:33 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sasb(t_stack **stack)
{
	int	swap;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	swap = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = swap;
}

void	rarb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*rot;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	rot = *stack;
	while (tmp->next)
		tmp = tmp->next;
	*stack = (*stack)->next;
	tmp->next = rot;
	rot->next = NULL;
	rot->prev = tmp;
	(*stack)->prev = NULL;
}

void	rrarrb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*rot;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	rot = *stack;
	while (rot->next)
	{
		tmp = rot;
		rot = rot->next;
	}
	rot->next = *stack;
	rot->prev = NULL;
	tmp->next = NULL;
	(*stack)->prev = rot;
	(*stack) = rot;
}

void	papb(t_stack **a, t_stack **b)
{
	int	n;

	n = (*a)->nbr;
	ft_addfirstnbr(b, n);
	ft_rmfirstnbr(a);
}
