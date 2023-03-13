/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:18:00 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/13 19:03:08 by adi-nata         ###   ########.fr       */
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

void	ft_test(t_stack *stack)
{
	/* while (stack->prev)
		stack = stack->prev; */
	while (stack)
	{
		ft_printf("%d\n", stack->nbr);
		stack = stack->next;
	}
}

void	minisolver(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		ft_solve2 (a);
	else if (size == 3)
		ft_solve3 (a);
	else if (size == 4)
		ft_solve4 (a, b);
	else if (size == 5)
		ft_solve5to50 (a, b, size);
}

void	bigsolver(t_stack **a, t_stack **b, int size)
{
	if (size <= 50)
		ft_solve5to50(a, b, size);
	else
		ft_lis(a, b, size);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = 0;
	ft_stackinit (ac, av, &a);
	size = ft_lstsize (a);
	//ft_test(a);
	if (size < 6)
		minisolver(&a, &b, size);
	else
		bigsolver(&a, &b, size);
	ft_test(a);
	return (0);
}
