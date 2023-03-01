/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:18:00 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/01 16:13:47 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackinit(int ac, char **av, t_stack **push)
{
	int i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(push, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

int	ft_minimum(t_stack *push)
{
	int	min;

	min = push->nbr;
	while (push)
	{
		if (push->nbr < min)
			min = push->nbr;
		push = push->next;
	}
	return (min);
}

void	ft_solve2(t_stack *a)
{
	(void)a;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_stackinit(ac, av, &a);
	if (ac > 1)
	{
		if (ac == 3)
			ft_solve2(a);
	}
	/*while (a)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	}*/
	return (0);
}
