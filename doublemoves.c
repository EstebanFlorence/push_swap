/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublemoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:06:34 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/12 20:11:52 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	sasb(a, 'r');
	sasb(b, 'r');
	ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rarb (a, 'r');
	rarb (b, 'r');
	ft_printf ("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rrarrb (a, 'r');
	rrarrb (b, 'r');
	ft_printf ("rrr\n");
}
