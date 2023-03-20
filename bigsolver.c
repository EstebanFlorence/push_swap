/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:37:55 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/20 17:05:45 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nonlis(t_stack **a, t_stack **b, t_lis *listruct, int *lis)
{
	int		i;
	int		pos;
	int		stay;
	t_stack	*tmpstack;

	i = 0;
	pos = 1;
	stay = 0;
	tmpstack = *a;
	while (listruct->stacklen > listruct->lislen)
	{
		while (i < listruct->lislen)
		{
			if (tmpstack->nbr == lis[i])
				listruct->stay++;
			i++;
		}
		ft_stayornot(a, b, &tmpstack, listruct);
		i = 0;
	}
}

void	ft_stayornot(t_stack **a, t_stack **b, t_stack **tmpstack, \
			t_lis *listruct)
{
	int	pos;

	pos = 1;
	if (!listruct->stay)
	{
		pos = ft_position(*a, (*tmpstack)->nbr);
		ft_whichalf(a, b, pos, listruct->stacklen);
		*tmpstack = (*tmpstack)->next;
		listruct->stacklen--;
	}
	else
	{
		*tmpstack = (*tmpstack)->next;
		listruct->stay = 0;
	}
}

void	ft_moves(t_stack **a, t_stack **b)
{
	int	sizeb;
	int	mova;
	int	movb;

	sizeb = ft_lstsize(*b);
	mova = (int *)malloc(sizeb * sizeof(int));
	movb = (int *)malloc(sizeb * sizeof(int));
	

	free (mova);
	free (movb);
}

void	ft_movinnit(t_stack *stack, int *mov, int size)
{
	int	i;
	int	pos;

	i = 0;
	pos = 1;
	while (mov[i])
	{

	}
}
