/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:18:00 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/08 00:25:45 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackinit(int ac, char **av, t_stack **stack)
{
	int i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(av[i])));
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

void	ft_solve2(t_stack *stack)
{
	if (stack->nbr != ft_minimum(stack))
		sasb(stack, 'a');
}

void	ft_solve3(t_stack *stack)
{
	rarb(&stack, 'a');
}


void	ft_test(t_stack *stack)
{
	while(stack->prev)
		stack = stack->prev;
	while (stack)
	{
		ft_printf("%d\n", stack->nbr);
		stack = stack->next;
	}
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
	ft_test(a);
	if (size == 2)
		ft_solve2(a);
	else if (size == 3)
		ft_solve3(a);
	ft_test(a);
	return (0);
}
