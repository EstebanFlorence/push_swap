/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:18:00 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/08 23:24:08 by adi-nata         ###   ########.fr       */
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
	int	a;
	int	b;
	int	c;

	a = stack->nbr;
	b = stack->next->nbr;
	c = stack->next->next->nbr;
	if (b < a && a < c)
		sasb (stack, 'a');
	else if (c < a && a < b)
		rrarrb (&stack, 'a');
	else if (b < c && c < a)
		rarb (&stack, 'a');
	else if (a < c && c < b)
	{
		sasb (stack, 'a');
		rarb (&stack, 'a');
	}
	else if (c < b && b < a)
	{
		sasb (stack, 'a');
		rrarrb (&stack, 'a');
	}
}

void	ft_solve4(t_stack *a, t_stack *b)
{
	int	n;
	int	x;
	int	y;
	int	z;
	
	papb (&a, &b, 'b');
	ft_solve3 (a);
	while (a->prev)
		a = a->prev;
	papb (&b, &a, 'a');
	n = a->nbr;
	x = a->next->nbr;
	y = a->next->next->nbr;
	z = a->next->next->next->nbr;
	if (y < n && n < z)
	{
		rrarrb (&a, 'a');
		sasb (a, 'a');
		rrarrb (&a, 'a');
		rrarrb (&a, 'a');
	}
	else if (x < n && n < y)
		sasb (a, 'a');
	else if (n > z)
		rrarrb (&a, 'a');
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
	ft_stackinit (ac, av, &a);
	size = ft_lstsize (a);
	ft_test(a);
	if (size == 2)
		ft_solve2 (a);
	else if (size == 3)
		ft_solve3 (a);
	else if (size == 4)
		ft_solve4 (a, b);
	ft_test(a);
	return (0);
}
