/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:02:24 by astalha           #+#    #+#             */
/*   Updated: 2023/01/01 19:03:10 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
		int	max;

		while (!sorted(a))
		{
		max = get_max(*a);
		if ((*a)->next->next->content > (*a)->next->content && (*a)->content < (*a)->next->content)
			return ;
		if (max == 2)
			swap(*a,(*a)->next,'a');
		else if (max == 0)
			{
				rotate(a,'a');
				if ((*a)->content > (*a)->next->content)
				swap(*a,(*a)->next,'a');
			}
		else
		{
				reverse_rotate(a,'a');
			if ((*a)->content > (*a)->next->content)
				swap(*a,(*a)->next,'a');
		}	
		}
}

void 	sort_small(t_stack **a, t_stack **b, t_data info)
{
	int j ;
	int i;

	i = 0;
	j = 0;
	if (info.nbelem == 2)
	{
		if(get_min_value(*a) != (*a)->content)
			swap((*a),(*a)->next,'a');
		return ;
	}
	while(j < info.nbelem - 3)
	{
		i  = get_min_value(*a);
		if (i < info.nbelem / 2)
		{
			while (i != (*a)->content)
				rotate(a,'a');
		}
		else
			while (i != (*a)->content)
				reverse_rotate(a,'a');
		push_b(b,a);
		j++;	
	}
	 sort_3(a);
	while (*b)
		push_a(a,b);
}


int	callen(int n, t_data *info)
{
	int len;
	int i;
	int last;
	int j;
	i = 0;
	
		len = 1;
		last = n;
		while (i < info->nbelem)
		{
			if (info->arr[i] == n)
				break ;
			i++;
		}
			j = i + 1;
			if (j == info->nbelem)
				j = 0;
		while (info->arr[j] != n)
		{
			if (info->arr[j] > last)
			{
				last = info->arr[j];
				len++;
				j++;
				if (j  == info->nbelem)
					j = 0;
			}
			else
			{
			 j++;
			 if (j  == info->nbelem)
					j = 0;
			}
		}
	return len;
}
int		get_max_len(t_stack *a)
{
	int max;
	max = 1;
	while (a)
	{
		if (a->len > max)
			max = a->len;
		a = a->next;
	}
	return (max);
}
void	set_pnp(t_stack *a)
{
	t_stack *tmp;
	int max;
	int save;
	int last;
	tmp = a;
	save = 0;
	max = get_max_len(tmp);

	while (tmp)
	{
		if (tmp->len == max)
		{
			save = tmp->content;
			tmp->pnp = 1;
			if (tmp->next)
				tmp = tmp->next;
			else 
				tmp = a;
			break ;
		}
		tmp = tmp->next;
	}

	last = save;
	while (tmp->content != save)
	{
		
		 if (tmp->content > last)
			{
				last = tmp->content;
				tmp->pnp = 1;
				if (!tmp->next)
					tmp = a;
				else 
					tmp = tmp->next;
			}
		else
		{
			if(!tmp->next)
				tmp = a;
			else	
				tmp = tmp->next;
		}
	}
}