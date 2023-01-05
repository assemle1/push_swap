/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:03:20 by astalha           #+#    #+#             */
/*   Updated: 2023/01/05 18:51:50 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		minmax(t_stack *a, int n)
{
	int last;
	int index;

	index = 0;
    while (a)
    {
        if (a->content > n)
        {
            setlast(a,&last,&index);
            while (a)
	            {
		            if(a->content > n && a->content < last)
			        	setlast(a,&last,&index);
		                a = a->next;
	            }
            break;
        }
        a = a->next;
    }
	return (index);
}

void 	setlast(t_stack *a,int *last, int *index)
{
	*last = a->content;
	*index = a->index;
}
int		movsa(t_stack *a, int n)
{
	int last;
	int index;
	int mida;
	int movs;
	int size;
	
	index = 0;
	size = ft_lstsize(a);
	mida = (ft_lstsize(a) - 1) / 2;
        if (a->content > n)
        {
           setlast(a,&last,&index);
            while (a)
	            {
		            if(a->content > n && a->content < last)
			        	setlast(a,&last,&index);
		                a = a->next;
	            }
        }
	if (index <= mida)
		movs = index;
	else
		movs =  size - index;
	return (movs);
}
void	set_hops(t_stack *a,t_stack *b)
{
	int midb;
	int mov;
	int size;

	size = ft_lstsize(b);
	midb = (ft_lstsize(b) - 1) / 2;
	while (b)
	{
		if (b->index <= midb)
			mov = b->index + 1;
		else
			mov =  size - b->index + 1;
		mov = mov + movsa(a,b->content);
		b->movs = mov;
		b = b->next;
	}
}
void set_len(t_stack **a, t_data *info)
{
	t_stack *tmp;

	 tmp = *a;
	while (tmp)
	{
		if ((tmp)->len != 0)
			(tmp)->len = 0;
		(tmp)->len = callen((tmp)->content,info);
		(tmp) = (tmp)->next;
	}
}
