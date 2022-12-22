/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:03:24 by astalha           #+#    #+#             */
/*   Updated: 2022/12/19 16:45:54 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check(char *av)
{
    int i;
    int j;
    i = 0;
    while (av[i])
    {
        if (av[i] == 32)
            i++;
        else if(!ft_isdigit(av[i]))
            return 0;
        i++;
    }
    return i;
}

int check_double(data *info)
{
    int i;
    int j;

    i = 0;
    while (i < info->nbelem)
    {
        j = 0;
        while (j < info->nbelem)
        {
             if(i != j && info->arr[i] == info->arr[j])
                return (0);
            j++;
        }
        i++;
    }
    return (i);
}

int issorted(data *info)
{
    int i;
    int j;

    i = 0;
    while (i < info->nbelem)
    {
        j = i + 1;
        while (j < info->nbelem)
        {
             if(info->arr[i] > info->arr[j])
                return (0);
            j++;
        }
        i++;
    }
    return (i);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	n;
	size_t	signe;

	i = 0;
	n = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	return ((int)n * signe);
}
void	swap(p_stack *leftnode, p_stack *rightnode, char stack)
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

void    ss(p_stack *a, p_stack *b)
{
    if (!a || !b)
        return ;
    swap(a,a->next,'f');
    swap(b,b->next,'f');
    ft_putstr_fd("ss\n",1);
}
void    push_a(p_stack **a, p_stack **b)
{
    p_stack *tmp;

    if (!*b)
        return ;
    tmp = (*b)->next;
    ft_lstadd_front(a,ft_lstnew((*b)->content));
    free(*b);
    *b = tmp;
    ft_putstr_fd("pa\n",1);
}

void    push_b(p_stack **b, p_stack **a)
{
       p_stack *tmp;

    if (!*a)
        return ;
    tmp = (*a)->next;
    ft_lstadd_front(b,ft_lstnew((*a)->content));
    free(*a);
    *a = tmp;
    ft_putstr_fd("pb\n",1);
}
void    rotate(p_stack **a, char index)
{
    p_stack *help;
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
void    rr(p_stack  **a, p_stack **b)
{
    rotate(a,'h');
    rotate(b,'h');
    ft_putstr_fd("rr\n",1);
}

void    reverse_rotate(p_stack  **a, char index)
{
    p_stack *help;
    p_stack *help2;

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
    else
        return ;
}

void    rrr(p_stack **a, p_stack **b)
{
    reverse_rotate(a,'g');
    reverse_rotate(b,'g');
    ft_putstr_fd("rrr\n",1);
}