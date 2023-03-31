/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:06:34 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/31 16:56:47 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
