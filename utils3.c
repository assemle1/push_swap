/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:02:24 by astalha           #+#    #+#             */
/*   Updated: 2023/01/05 18:52:16 by astalha          ###   ########.fr       */
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
void	push_min(t_stack **a, t_stack **b, t_data *info)
{
	int i;

		i  = get_min_value(*a);
		if (i < info->nbelem / 2)
		{
			while (i != (*a)->content)
				rotate(a,'a');
		}
		else
			while (i != (*a)->content)
				reverse_rotate(a,'a');
		push_b(b,a);
}

void 	sort_small(t_stack **a, t_stack **b, t_data *info)
{
	int j ;
	int i;

	i = 0;
	j = 0;
	if (info->nbelem == 2)
	{
		swap((*a),(*a)->next,'a');
		return ;
	}
	while(j < info->nbelem - 3)
	{
		push_min(a,b,info);
		j++;	
	}
	 sort_3(a);
	while (*b)
		push_a(a,b);
}

void 	lenght(t_data *info, int *j, int *len ,int *last)
{
	if (info->arr[*j] > *last)
			{
				*last = info->arr[*j];
				(*len)++;
				(*j)++;
				if (*j  == info->nbelem)
					*j = 0;
			}
			else
			{
			 (*j)++;
			 if (*j  == info->nbelem)
					*j = 0;
			}
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
			lenght(info,&j,&len,&last);
	return len;
}
