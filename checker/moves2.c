/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:06:34 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/02 01:44:52 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack **a, t_stack **b)
{
	sasb(a);
	sasb(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rarb (a);
	rarb (b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrarrb (a);
	rrarrb (b);
}
