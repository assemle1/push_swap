/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:55:35 by astalha           #+#    #+#             */
/*   Updated: 2023/01/05 22:40:03 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*link_args(t_data	*info)
{
	t_stack *head;
	t_stack *new;
	int i;

	i = 0;
	head = NULL;
	while (i < info->nbelem)
	{
		printf("[%d]\n",info->arr[i]);
		new = ft_lstnew(info->arr[i]);
		if (new == NULL)
			return (NULL);
		ft_lstadd_back(&head,new);
		i++;
	}
	return head;
}

void make_arr(t_data *info)
{
	int i;
	i = 0;
	while (info->args[i])
	{
		info->arr[i] = ft_atoi(info->args[i]);
		i++;
	}
}

int	count(char *str[])
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int sorted(t_stack **a)
{
	t_stack *head;
	head = *a;
	while (head->next)
    {
		if (head->content > head->next->content)
		    return (0);
        head = head->next;
	}
	return (1);
}