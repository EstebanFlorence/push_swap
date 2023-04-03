/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:06:34 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/03 18:55:13 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack **a, t_stack **b)
{
	if (*b == NULL)
	{
		ft_printf("KO\n");
		ft_freechecker(a, b);
		exit (EXIT_FAILURE);
	}
	sasb(a);
	sasb(b);
}

void	rr(t_stack **a, t_stack **b)
{
	if (*b == NULL)
	{
		ft_printf("KO\n");
		ft_freechecker(a, b);
		exit (EXIT_FAILURE);
	}
	rarb (a);
	rarb (b);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (*b == NULL)
	{
		ft_printf("KO\n");
		ft_freechecker(a, b);
		exit (EXIT_FAILURE);
	}
	rrarrb (a);
	rrarrb (b);
}
