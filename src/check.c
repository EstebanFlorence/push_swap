/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:30:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/29 20:08:05 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check1(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
			{
				write(2, "Error\n", 6);
				ft_printf("Some arguments aren’t integers\n");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check2(int ac, char **av)
{
	int			i;
	long int	nbr;

	i = 1;
	while (i < ac)
	{
		nbr = ft_atol(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			write(2, "Error\n", 6);
			ft_printf("Some arguments are bigger or smaller than an integer\n");
			return (0);
		}
		i++;
	}
	return (1);
}

long int	ft_atol(const char *nbr)
{
	int			sign;
	long int	res;

	sign = 1;
	res = 0;
	while (*nbr == ' ' || \
			(*nbr >= '\t' && *nbr <= '\r'))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		res = res * 10 + *nbr - '0';
		nbr++;
	}
	return (res * sign);
}

int	ft_check3(t_stack *stack)
{
	int		dub;
	t_stack	*tmp;
	t_stack	*head;

	tmp = stack->next;
	head = stack;
	while (tmp)
	{
		dub = 0;
		stack = head;
		while (stack)
		{
			if (stack->nbr == tmp->nbr)
				dub++;
			if (dub > 1)
			{
				write(2, "Error\n", 6);
				ft_printf("There are duplicates\n");
				return (0);
			}
			stack = stack->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
