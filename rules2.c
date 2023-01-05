/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:42:06 by astalha           #+#    #+#             */
/*   Updated: 2023/01/01 16:48:36 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_stack **a, char index)
{
    t_stack *help;
    int tmp;
    help = *a;
    tmp = help->content;
    while (help->next)
    {
        help->content = help->next->content;
        help = help->next;
        if (!help->next)
            help->content = tmp;
    }
    if (index == 'a')
        ft_putstr_fd("ra\n",1);
    else if (index == 'b')
        ft_putstr_fd("rb\n",1);
}
void    rr(t_stack  **a, t_stack **b)
{
    rotate(a,'h');
    rotate(b,'h');
    ft_putstr_fd("rr\n",1);
}

void    reverse_rotate(t_stack  **a, char index)
{
    t_stack *help;
    t_stack *help2;

    help = ft_lstlast(*a);
    help2 = *a;
    while (help2)
    {
        if (!(help2->next->next))
        {
            help2->next = NULL;
            break;
        }
        help2 = help2->next;
    }
        help->next = (*a);
        *a = help;
    if (index == 'a')
        ft_putstr_fd("rra\n",1);
    else if (index == 'b')
        ft_putstr_fd("rrb\n",1);
}

void    rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a,'g');
    reverse_rotate(b,'g');
    ft_putstr_fd("rrr\n",1);
}

