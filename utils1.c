/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:55:35 by astalha           #+#    #+#             */
/*   Updated: 2023/01/01 22:11:08 by astalha          ###   ########.fr       */
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

void sort_array(int *arr, t_data info )
{
    int i;
    int j;
    int tmp;

    i = 0;
   j = 0;
    while (i < info.nbelem)
    {
        j = i + 1;
        while (j < info.nbelem)
        {
            if (arr[j] < arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
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