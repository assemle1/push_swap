/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:04:14 by astalha           #+#    #+#             */
/*   Updated: 2023/01/01 19:56:02 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lastlst;

	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	lastlst = ft_lstlast (*lst);
	lastlst->next = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

int     ft_lstsize(t_stack *lst)
{
        int             i;
        t_stack  *plst;

        i = 0;
        if (!lst)
                return (0);
        plst = lst;
        while (plst != NULL)
        {
                i++;
                plst = plst->next;
        }
        return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*plst;

	if (!lst)
		return (0);
	plst = lst;
	while (plst->next != NULL)
		plst = plst->next;
	return (plst);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *) malloc (sizeof (t_stack));
	if (!new)
		return (NULL);
	new->len = 0;
	new->index = 0;
	new->pnp = 0;
	new->content = content;
	new->next = NULL;
	return (new);
}