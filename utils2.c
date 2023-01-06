/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:01:06 by astalha           #+#    #+#             */
/*   Updated: 2023/01/06 16:01:13 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_stack *a)
{
	t_stack	*tmp;
	int		min;

	min = a->content;
	tmp = a;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	get_min_index(t_stack *a)
{
	t_stack	*tmp;
	int		min;
	int		index;

	min = a->content;
	tmp = a;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

int	get_max(t_stack *a)
{
	t_stack	*tmp;
	int		max;
	int		index;

	max = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

void	ft_index(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (a)
	{
		a->index = i++;
		a = a->next;
	}
	a = tmp;
}
