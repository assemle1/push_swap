/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:30:13 by astalha           #+#    #+#             */
/*   Updated: 2022/12/26 19:54:35 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	link_args(p_stack **list, data	info)
{
	p_stack *head;
	p_stack *new;
	int i;

	i = 0;
	head = NULL;
	while (i < info.nbelem)
	{
		new = ft_lstnew(info.arr[i]);
		ft_lstadd_back(&head,new);
		i++;
	}
	 *list = head;
}

void make_arr(data *info)
{
	int i;
	i = 0;
	while (info->args[i])
	{
		info->arr[i] = ft_atoi(info->args[i]);
		i++;
	}
	
}

void sort_array(long *arr, data info )
{
    int i;
    int j;
    long tmp;

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
int sorted(p_stack **a)
{
	p_stack *head;
	head = *a;
	while (head->next)
    {
		if (head->content > head->next->content)
		    return (0);
        head = head->next;
	}
	return (1);
}
int		get_min_value(p_stack *a)
{
	p_stack *tmp;
	int min;
	min = a->content;

	tmp = a;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return min;
}
int		get_max(p_stack *a)
{
	p_stack *tmp;
	int max;
	max = 0;
	int index;
	tmp = a;
	while (tmp)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return index;
}
void ft_index(p_stack **a, data info)
{
	p_stack *tmp;
	int i;
	i = 0;
	sort_array(info.arr,info);
	tmp = *a;
	while (*a)
	{
			(*a)->index= i;
				i++;
			*a = (*a)->next;
	}
	*a = tmp;
}

void	sort_3(p_stack **a)
{
		int	max;
		while (!sorted(a))
		{
		max = get_max(*a);
		if ((*a)->next->next->content > (*a)->next->content && (*a)->content < (*a)->next->content)
			return ;
		if (max == 2)
			swap(*a,(*a)->next,'a');
		else if (max == 0)
			{
				rotate(a,'a');
				if ((*a)->content > (*a)->next->content)
				swap(*a,(*a)->next,'a');
			}
		else
		{
				reverse_rotate(a,'a');
			if ((*a)->content > (*a)->next->content)
				swap(*a,(*a)->next,'a');
		}	
		}
}

void 	sort_small(p_stack **a, p_stack **b, data info)
{
	int j ;
	int i;
	i = 0;
	j = 0;

	if (info.nbelem == 2)
	{
		if(get_min_value(*a) != (*a)->content)
			swap((*a),(*a)->next,'a');
		return ;
	}
	while(j < info.nbelem - 3)
	{
		i  = get_min_value(*a);
		if (i < info.nbelem/2)
		{
			while (i != (*a)->content)
				rotate(a,'a');
		}
		else
			while (i != (*a)->content)
				reverse_rotate(a,'a');
		push_b(b,a);
		j++;	
	}
	 sort_3(a);
	while (*b)
		push_a(a,b);
}
sort_big(p_stack **a, p_stack **b,data info)
{
	int middle;
	int offset;

	offset = 
	middle = info.nbelem / 2;
	while (srted(a))
	{
		
	}
	
	
	
		
}
int	main(int ac, char *av[])
{
	char *params;
	p_stack *stack_a = NULL;
	 p_stack *stack_b = NULL;
	data	info;
	
	params = ft_strjoin(ac,av," ");
	info.args = ft_split(params, ' ');
	info.nbelem = count(info.args);
	info.arr = malloc(sizeof(long) * count(info.args));
	make_arr(&info);
	if (!check(params) || !check_double(&info))
	{
		ft_putstr_fd("Error\n",2);
		return (0);
	}
	if (issorted(&info))
		return (0);
	 link_args(&stack_a,info);
	 ft_index(&stack_a,info); 
	  sort_small(&stack_a,&stack_b,info);
	 printf("sorted : %d\n",sorted(&stack_a));
	while (stack_a)
	{
		printf(" %d ",stack_a->content);
		stack_a = stack_a->next;
	}
}	