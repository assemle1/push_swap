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
void	amovs(t_stack **a, int minmax, int mida, int size_a)
{
	if (minmax <= mida)
			do_action(a,1,minmax);
	else
		do_action(a,3,size_a - minmax); 	
}
void	bmovs(t_stack **b, int less, int midb,int size_b)
{
	if (less <= midb)
		do_action(b,2,less);
	else
		do_action(b,4,size_b - less);
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
void	set_a(t_stack **a, t_stack **b, int less, int size_b, int midb, int minmax)
{
	int size_a;
	int mida;
	int i;
	i = 0;
	size_a = ft_lstsize(*a);
	mida = (size_a - 1) / 2;
	if (less <= midb && minmax <= mida)
		do_rr(a, b, less, minmax);
	else if (less > midb && minmax > mida)
		do_rrr(a, b, less, minmax, size_a, size_b);
	else
	{
		amovs(a,minmax,mida,size_a);
		bmovs(b,less,midb,size_b);
	}
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
	int size_b;

	size_b = ft_lstsize(*b);
	less = get_less_movs(*b);
	set_a(a,b,less,size_b,midb,minmax(*a,getlessvalue(*b,less)));
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