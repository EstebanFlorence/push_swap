/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:08:39 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/25 20:29:36 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves(t_stack **a, t_stack **b)
{
	int		i;
	int		sizeb;
	int		*mova;
	int		*movb;

	i = 0;
	sizeb = ft_lstsize(*b);
	mova = (int *)malloc(sizeb * sizeof(int));
	movb = (int *)malloc(sizeb * sizeof(int));
	ft_calculator(a, b, mova, movb);
	i = ft_findbestmoves(mova, movb, sizeb);
	ft_makebestmoves(a, b, mova[i], movb[i]);
	free (mova);
	free (movb);
}

void	ft_calculator(t_stack **a, t_stack **b, int *mova, int *movb)
{
	int		i;
	int		sizeb;
	t_stack	*tmpb;

	i = 0;
	sizeb = ft_lstsize(*b);
	tmpb = *b;
	while (tmpb)
	{
		if (i <= sizeb / 2)
			movb[i] = i;
		else
			movb[i] = i - sizeb;
		if (ft_position2(*a, (tmpb->nbr)) <= ft_lstsize(*a) / 2)
			mova[i] = ft_position2(*a, tmpb->nbr);
		else
			mova[i] = ft_position2(*a, tmpb->nbr) - ft_lstsize(*a);
		i++;
		tmpb = tmpb->next;
	}
}

void	ft_makebestmoves(t_stack **a, t_stack **b, int x, int y)
{
	if (x >= 0 && y >= 0)
		move_plusplus (a, b, x, y);
	if (x >= 0 && y < 0)
		move_plusminus (a, b, x, y);
	if (x < 0 && y >= 0)
		move_minusplus (a, b, x, y);
	if (x < 0 && y < 0)
		move_minusminus (a, b, x, y);
}
