/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:49:02 by astalha           #+#    #+#             */
/*   Updated: 2023/01/06 15:40:12 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	amovs(t_stack **a, int minmax, int mida, int size_a)
{
	if (minmax <= mida)
		do_action(a, 1, minmax);
	else
		do_action(a, 3, size_a - minmax);
}

void	bmovs(t_stack **b, int less, int midb, int size_b)
{
	if (less <= midb)
		do_action(b, 2, less);
	else
		do_action(b, 4, size_b - less);
}

void	do_movs(t_stack **a, t_stack **b, int less, int minmax)
{
	int	size_a;
	int	mida;
	int	size_b;
	int	midb;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	mida = (size_a - 1) / 2;
	midb = (size_b - 1) / 2;
	if (less <= midb && minmax <= mida)
		do_rr(a, b, less, minmax);
	else if (less > midb && minmax > mida)
		do_rrr(a, b, less, minmax);
	else
	{
		amovs(a, minmax, mida, size_a);
		bmovs(b, less, midb, size_b);
	}
}
