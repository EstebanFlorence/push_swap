/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/21 19:25:12 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_position(t_stack *stack, int nbr)
{
	int	pos;

	pos = 1;
	while (stack->nbr != nbr)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	ft_position2(t_stack *stack, int nbr)
{
	int pos;

	pos = 0;
	while(stack)
	{
		if (nbr < stack->nbr && stack->nbr == ft_minimum(stack))
			return (pos);
		if (nbr > stack->nbr && nbr > stack->next->nbr \
				|| nbr > stack->nbr && !stack->next)
			return (pos + 1);
		else
			pos++;
		stack = stack->next;
	}
}
