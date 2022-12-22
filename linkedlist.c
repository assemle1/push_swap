/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:04:14 by astalha           #+#    #+#             */
/*   Updated: 2022/12/19 16:57:48 by astalha          ###   ########.fr       */
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
	
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

int     ft_lstsize(p_stack *lst)
{
        int             i;
        p_stack  *plst;

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

void    ft_lstclear(p_stack **lst)
{
        p_stack  *plst;

        if (!lst)
                return ;
        plst = *lst;
        while (plst != NULL)
        {
                free(plst);
				plst = NULL;
                plst = plst->next;
        }
        *lst = NULL;
}