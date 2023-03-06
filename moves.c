/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:14:19 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/06 21:14:35 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else
		ft_printf("rb\n");
}

void	rrarrb(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*rot;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
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
	else
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
	else
		ft_printf("pb\n");
}

void	ft_addfirstnbr(t_stack **stack, int n)
{
	t_stack	*new;

	new = ft_lstnew(n);
	if (!*stack)
		*stack = new;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

void	ft_rmfirstnbr(t_stack **stack)
{
	if ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
}