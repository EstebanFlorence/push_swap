/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:18:00 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/02 19:33:10 by adi-nata         ###   ########.fr       */
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

int	ft_minimum(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

void	ft_rarb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*rot;

	
}

void	ft_solve2(t_stack *stack)
{
	if (stack->nbr != ft_minimum(stack))
		ft_rarb(stack);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = 0;
	ft_stackinit(ac, av, &a);
	size = ft_lstsize(a);
	if (size == 2)
		ft_solve2(a);
	
	/*while (a)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	}*/
	return (0);
}
