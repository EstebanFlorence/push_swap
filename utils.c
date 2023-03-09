/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:13:09 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/09 23:25:26 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minimum(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
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

