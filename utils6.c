/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:52:59 by astalha           #+#    #+#             */
/*   Updated: 2023/01/06 16:27:15 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_less_movs(t_stack *b)
{
	int	index;
	int	movs;

	index = 0;
	movs = b->movs;
	while (b)
	{
		if (movs > b->movs)
		{
			movs = b->movs;
			index = b->index;
		}
		b = b->next;
	}
	return (index);
}

int	get_max_len(t_stack *a)
{
	int	max;

	max = 1;
	while (a)
	{
		if (a->len > max)
			max = a->len;
		a = a->next;
	}
	return (max);
}

void	pnp(t_stack **tmp, t_stack *a, int *last)
{
	if ((*tmp)->content > *last)
	{
		*last = (*tmp)->content;
		(*tmp)->pnp = 1;
		if (!(*tmp)->next)
			(*tmp) = a;
		else
			(*tmp) = (*tmp)->next;
	}
	else
	{
		if (!(*tmp)->next)
			(*tmp) = a;
		else
			(*tmp) = (*tmp)->next;
	}
}

void	set_pnp(t_stack *a)
{
	t_stack	*tmp;
	int		max;
	int		save;
	int		last;

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
		pnp(&tmp, a, &last);
}
