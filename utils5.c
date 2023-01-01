/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:04:00 by astalha           #+#    #+#             */
/*   Updated: 2023/01/01 20:56:35 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_a(t_stack **a, int minmax)
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

void	do_action(t_stack **b, char acc, int times)
{
	int i;
	i = 0;
	while (i < times)
	{
		if (acc == 'r')
			rotate(b,'b');
		else if (acc == 's')
			reverse_rotate(b,'b');
		else
			return ;
		i++;
	}
}

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

void	set_b(t_stack **a, t_stack **b, int midb)
{
	int  less;
	int size;

	size = ft_lstsize(*b);
	less = get_less_movs(*b);
	set_a(a,minmax(*a,getlessvalue(*b,less)));
	if (!less)
	{
		push_a(a,b);
		return ;
	}
	if (less <= midb)
		do_action(b,'r',less);
	else
		do_action(b,'s',size - less);
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
	 set_b(a,b,midb);
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