/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:42:19 by astalha           #+#    #+#             */
/*   Updated: 2023/01/01 21:17:55 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *leftnode, t_stack *rightnode, char stack)
{
    int tmp;
    if (!leftnode || !rightnode)
        return ;
     tmp = leftnode->content;
     leftnode->content = rightnode->content;
     rightnode->content = tmp; 
     if (stack == 'a')
        ft_putstr_fd("sa\n",1);
    else if (stack == 'b')
        ft_putstr_fd("sb\n",1);
}

void    ss(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return ;
    swap(a,a->next,'f');
    swap(b,b->next,'f');
    ft_putstr_fd("ss\n",1);
}
void    push_a(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!*b)
        return ;
    tmp = (*b)->next;
    ft_lstadd_front(a,ft_lstnew((*b)->content));
    free(*b);
    *b = tmp;
    ft_putstr_fd("pa\n",1);
}

void    push_b(t_stack **b, t_stack **a)
{
       t_stack *tmp;

    if (!*a)
        return ;
    tmp = (*a)->next;
    ft_lstadd_front(b,ft_lstnew((*a)->content));
   free(*a);
    *a = tmp;
    ft_putstr_fd("pb\n",1);
}
