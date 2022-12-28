/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:30:13 by astalha           #+#    #+#             */
/*   Updated: 2022/12/28 16:51:42 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

p_stack	*link_args(data	*info)
{
	p_stack *head;
	p_stack *new;
	int i;

	i = 0;
	head = NULL;
	while (i < info->nbelem)
	{
		new = ft_lstnew(info->arr[i]);
		if (new == NULL)
			return NULL; // TODO: free head before return
		ft_lstadd_back(&head,new);
		i++;
	}
	return head;
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

void sort_array(int *arr, data info )
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
void ft_index(p_stack *a)
{
	p_stack *tmp;
	int i;
	i = 0;
	tmp = a;
	while (a)
	{
			a->index= i++;
			a = a->next;
	}
	a = tmp;
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

// void	setlen(p_stack **a,int n ,int len)
// {
// 	p_stack *tmp;
// 	tmp = *a;
// 	while(*a)
// 	{
// 		if ((*a)->content == n)
//         {
// 			(*a)->len = len;
//             *a = tmp;
//             return ;
//         }
// 		(*a) = (*a)->next;
// 	}
// 	*a = tmp;
// }
int	callen(int n, data *info)
{
	int len;
	int i;
	int last;
	int j;
	i = 0;
	
		len = 1;
		last = n;
		while (i < info->nbelem)
		{
			if (info->arr[i] == n)
				break ;
			i++;
		}
			j = i + 1;
			if (j == info->nbelem)
				j = 0;
		while (info->arr[j] != n)
		{
			if (info->arr[j] > last)
			{
				last = info->arr[j];
				len++;
				j++;
				if (j  == info->nbelem)
					j = 0;
			}
			else
			{
			 j++;
			 if (j  == info->nbelem)
					j = 0;
			}
		}
	return len;
}
int		get_max_len(p_stack *a)
{
	int max;
	max = 1;
	while (a)
	{
		if (a->len > max)
			max = a->len;
		a = a->next;
	}
	return (max);
}
void	set_pnp(p_stack **a)
{
	p_stack *tmp;
	int max;
	int save;
	tmp = *a;
	max = get_max_len(tmp);
	while (tmp)
	{
		if (tmp->len == max)
		{
			save = tmp->content;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp && tmp->content != save)
	{
		if (!tmp->next)
			tmp = *a;
		else if (tmp->content > save)
		tmp = tmp->next;
	}
	
	
}
void set_len(p_stack **a, data *info)
{
	p_stack *tmp;

	 tmp = *a;
	while (tmp)
	{
		if ((tmp)->len != 0)
			(tmp)->len = 0;
		(tmp)->len = callen((tmp)->content,info);
		(tmp) = (tmp)->next;
	}
}
// void sort_big(p_stack **a, p_stack **b, data info)
// {
// 	int i;
// 	int j;
// 	int last;
// 	p_stack *tmp;
// 	tmp = *a;
// 	i = 0;
// 	j = 0;
// 	last = 0;
// 	int len = 0;
// 	(*b)->next = ft_lstnew(5);
	
// }
// sort_big(p_stack **a, p_stack **b,data info)
// {
// 	int middle;
// 	int offset;

// 	offset = 
// 	middle = info.nbelem / 2;
// 	while (srted(a))
// 	{
		
// 	}
	
	
	
		
// }
int	main(int ac, char *av[])
{
	char *params;
	p_stack *stack_a;
	p_stack *stack_b = NULL;
	data	info;
	
	params = ft_strjoin(ac,av," ");
	info.args = ft_split(params, ' ');
	info.nbelem = count(info.args);
	info.arr = malloc(sizeof(int) * count(info.args));
	make_arr(&info);
	if (!check(params) || !check_double(&info))
	{
		ft_putstr_fd("Error\n",2);
		return (0);
	}
	if (issorted(&info))
		return (0);
	 stack_a = link_args(&info);
	 ft_index(stack_a); 
	 printf("sorted : %d\n",sorted(&stack_a));
	 stack_b = ft_lstnew(5);
	//  callen(4,info);
  set_len(&stack_a,&info);
	//   sort_big(&stack_a,&stack_b,info);
	// stack_b = stack_a;
	while (stack_a)
	{
		printf(" %d ",stack_a->index);
		stack_a = stack_a->next;
	}
	// stack_a = stack_b;
	// while (stack_a)
	// {
	// 	printf(" %d ",stack_a->len);
	// 	stack_a = stack_a->next;
	// }
}	