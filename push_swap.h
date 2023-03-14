/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:42:28 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/14 22:57:13 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"

void		ft_stackinit(int ac, char **av, t_stack **stack);
int			ft_minimum(t_stack *stack);
void		ft_addfirstnbr(t_stack **stack, int n);
void		ft_rmfirstnbr(t_stack **stack);
void		minisolver(t_stack **a, t_stack **b, int size);
void		bigsolver(t_stack **a, t_stack **b, int size);
void		ft_solve2(t_stack **stack);
void		ft_solve3(t_stack **stack);
void		ft_solve4(t_stack **a, t_stack **b);
void		ft_solve5(t_stack **a, t_stack **b, int size);
void		ft_solve5to50(t_stack **a, t_stack **b, int size);
int			ft_position(t_stack *stack);
void		ft_whichalf(t_stack **a, t_stack **b, int pos, int size);
void		ft_putback(t_stack **a, t_stack **b, int size, int tmpsize);
int			ft_lis(t_stack **stack, int **lis);
void		ft_lisarr(int **lis, int (*tmplis)[100], int len);

//	MOVES

void		sasb(t_stack **stack, char c);
void		rarb(t_stack **stack, char c);
void		rrarrb(t_stack **stack, char c);
void		papb(t_stack **a, t_stack **b, char c);
void		ss(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);

void		ft_test(t_stack *stack);

#endif