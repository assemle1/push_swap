/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:44:17 by astalha           #+#    #+#             */
/*   Updated: 2023/01/05 18:46:22 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_double(t_stack **a, t_stack **b, int acc, int times)
{
	int i;
	i = 0;
	while (i < times)
	{
		if (acc == 1)
			rr(a, b);
		else if (acc == 2)
			rrr(a, b);
		i++;
	}
}

void	do_rr(t_stack **a, t_stack **b, int less, int minmax)
{
	if (less < minmax)
		{
			do_double(a,b,1,less);
			do_action(a,1,minmax - less);
		}
	else if (less > minmax)
		{
			do_double(a,b,1,minmax);
			do_action(b,2,less - minmax);
		}
	else 
			do_double(a,b,1,less);
}
void	do_rrr(t_stack **a, t_stack **b, int less, int minmax, int size_a, int size_b)
{
	if (size_b - less < size_a - minmax)
		{
			do_double(a,b,2,size_b - less);
			do_action(a,3,(size_a - minmax) - (size_b - less));
		}
	else if (size_b - less > size_a - minmax)
		{
			do_double(a,b,2,size_a - minmax);
			do_action(b,4,(size_b - less) - (size_a - minmax));
		}
	else
			do_double(a,b,2,size_a - minmax);
}
void	do_action(t_stack **b, int acc, int times)
{
	int i;
	i = 0;
	while (i < times)
	{
		if (acc == 1)
			rotate(b,'a');
		if (acc == 2)
			rotate(b,'b');
		else if (acc == 3)
			reverse_rotate(b,'a');
		else if (acc == 4)
			reverse_rotate(b,'b');
		i++;
	}
}
void	a_set(t_stack **a, int minmax)
{
	int size;
	int mida;
	int i;
	i = 0;
	size = ft_lstsize(*a);
	mida = (size - 1) / 2;
		if (minmax <= mida)
			while (i < minmax)
			{
				rotate(a,'a');
				i++;
			}
		else
			while (i < size - minmax)
			{
				reverse_rotate(a,'a');
				i++;
			}	 	
}