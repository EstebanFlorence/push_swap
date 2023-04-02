/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:08:25 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/02 02:01:57 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (!ft_check1(ac, av))
		return (0);
	if (!ft_check2(ac, av))
		return (0);
	a = NULL;
	b = NULL;
	ft_stackinit (ac, av, &a);
	if (!ft_check3(a))
	{
		ft_freestack(a);
		return (0);
	}
	ft_read(&a, &b);
	ft_freestack(a);
	ft_freestack(b);
	return (0);
}
