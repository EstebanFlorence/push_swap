/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:06:34 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/29 19:18:37 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack **a, t_stack **b, char *line)
{
	if (*b == NULL || *a == NULL)
		ft_error(a, b, line);
	sasb(a);
	sasb(b);
}

void	rr(t_stack **a, t_stack **b, char *line)
{
	if (*b == NULL || *a == NULL)
		ft_error(a, b, line);
	rarb (a);
	rarb (b);
}

void	rrr(t_stack **a, t_stack **b, char *line)
{
	if (*b == NULL || *a == NULL)
		ft_error(a, b, line);
	rrarrb (a);
	rrarrb (b);
}
