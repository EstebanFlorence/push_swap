/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:14:19 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/08 00:05:11 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sasb(t_stack *stack, char c)
{
	int	swap;

	if (stack == NULL || stack->next == NULL)
		return ;
	swap = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = swap;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	rarb(t_stack **stack, char c)
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
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	rrarrb(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*rot;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	rot = *stack;
	while (tmp->next)
	{
		rot = tmp;
		tmp = tmp->next;
	}
	rot->next = NULL;
	tmp->next = *stack;
	tmp->prev = NULL;
	tmp->next->prev = tmp;
	*stack = tmp;
	if (c == 'a')
		ft_printf ("rra\n");
	else if (c == 'b')
		ft_printf ("rrb\n");
}

void	papb(t_stack **a, t_stack **b, char c)
{
	int	n;

	n = (*a)->nbr;
	ft_addfirstnbr(b, n);
	ft_rmfirstnbr(a);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}
