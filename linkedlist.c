/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:04:14 by astalha           #+#    #+#             */
/*   Updated: 2022/12/18 22:37:10 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(p_stack **lst, p_stack *new)
{
	p_stack	*lastlst;

	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	lastlst = ft_lstlast (*lst);
	lastlst->next = new;
}

void	ft_lstadd_front(p_stack **lst, p_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
    *lst = new;
}

void	ft_lstdelone(p_stack **lst)
{
	
}

p_stack	*ft_lstlast(p_stack *lst)
{
	p_stack	*plst;

	if (!lst)
		return (0);
	plst = lst;
	while (plst->next != NULL)
		plst = plst->next;
	return (plst);
}

p_stack	*ft_lstnew(int content)
{
	p_stack	*new;

	new = (p_stack *) malloc (sizeof (new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
