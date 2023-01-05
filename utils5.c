/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:04:00 by astalha           #+#    #+#             */
/*   Updated: 2023/01/05 18:49:27 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	getlessvalue(t_stack *b,int less)
{
	while (b)
	{
		if (b->index == less)
			return (b->content);
		b = b->next;
	}
	return 0;
}

void	pushsort(t_stack **a, t_stack **b, int midb)
{
	int  less;
	int size_b;

	size_b = ft_lstsize(*b);
	less = get_less_movs(*b);
	do_movs(a,b,less,size_b,midb,minmax(*a,getlessvalue(*b,less)));
	push_a(a,b);
}

void	push_back(t_stack **a, t_stack **b)
{
	int midb;

	while (*b)
	{
	ft_index(*a);
	ft_index(*b);
	midb = (ft_lstsize(*b) - 1) / 2;
	set_hops(*a,*b);
	 pushsort(a,b,midb);
	}
}

void sort_big(t_stack **a, t_stack **b, t_data *info)
{
	int max;
	int midb;

	set_len(a,info);
	set_pnp(*a);
	max = get_max_len(*a);
	while (ft_lstsize(*a) > max)
	{
		if ((*a)->pnp == 0)
			push_b(b,a);
		else
			reverse_rotate(a,'a');
	}
	push_back(a,b);
	ft_index(*a);
	midb = ((ft_lstsize(*a) - 1) / 2);
	if (midb >= get_min_index(*a))
		while ((*a)->content != get_min_value(*a))
			rotate(a,'a');
	else
			while ((*a)->content != get_min_value(*a))
			reverse_rotate(a,'a');
}