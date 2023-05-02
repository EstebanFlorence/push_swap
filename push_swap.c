/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:08:25 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/29 16:01:47 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackinit(int ac, char **av, t_stack **stack)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

void	minisolver(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		ft_solve2 (a);
	else if (size == 3)
		ft_solve3 (a);
	else if (size == 5)
		ft_solve5 (a, b, size);
}

void	bigsolver(t_stack **a, t_stack **b, int size)
{
	int		*lis;
	t_lis	*listruct;

	lis = NULL;
	listruct = (t_lis *)malloc(sizeof(t_lis));
	ft_lisinnit(listruct, a, size);
	ft_lis(listruct, a, &lis);
	ft_nonlis(a, b, listruct, lis);
	while (ft_lstsize(*b))
		ft_moves(a, b);
	ft_order(a, size);
	ft_freelis(listruct);
	free (lis);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (!ft_check1(ac, av))
		return (0);
	if (!ft_check2(ac, av))
		return (0);
	a = NULL;
	b = NULL;
	size = 0;
	ft_stackinit (ac, av, &a);
	if (!ft_check3(a))
	{
		ft_freestack(a);
		return (0);
	}
	size = ft_lstsize (a);
	if (size < 6)
		minisolver(&a, &b, size);
	else
		bigsolver(&a, &b, size);
	ft_freestack (a);
	ft_freestack (b);
	return (0);
}
