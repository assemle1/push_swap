/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:30:13 by astalha           #+#    #+#             */
/*   Updated: 2022/12/29 23:36:52 by astalha          ###   ########.fr       */
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
void	set_pnp(p_stack *a)
{
	p_stack *tmp;
	int max;
	int save;
	int last;
	tmp = a;
	save = 0;
	max = get_max_len(tmp);

	while (tmp)
	{
		if (tmp->len == max)
		{
			save = tmp->content;
			tmp->pnp = 1;
			if (tmp->next)
				tmp = tmp->next;
			else 
				tmp = a;
			break ;
		}
		tmp = tmp->next;
	}

	last = save;
	while (tmp->content != save)
	{
		
		 if (tmp->content > last)
			{
				last = tmp->content;
				tmp->pnp = 1;
				if (!tmp->next)
					tmp = a;
				else 
					tmp = tmp->next;
			}
		else
		{
			if(!tmp->next)
				tmp = a;
			else	
				tmp = tmp->next;
		}
	}
}
int		minmax(p_stack *a, int n)
{
	int last;
	int mida;
	int index;
	// int size = ft_lstsize(a);
	index = 0;
	mida = (ft_lstsize(a) - 1) / 2;
    while (a)
    {
        if (a->content > n)
        {
            last = a->content;
			index = a->content;
            while (a)
	            {
		            if(a->content > n && a->content < last)
					{
			        	last = a->content;
						index = a->index;
					}
		                a = a->next;
	            }
            break;
        }
        a = a->next;
    }
	return (index);
}
int		movsa(p_stack *a, int n)
{
	int last;
	int index = 0;;
	int mida;
	int movs = 0;
	int size = ft_lstsize(a);
	mida = (ft_lstsize(a) - 1) / 2;
    while (a)
    {
        if (a->content > n)
        {
            last = a->content;
			index = a->index;
            while (a)
	            {
		            if(a->content > n && a->content < last)
					{
			        	last = a->content;
						index = a->index;
					}
		                a = a->next;
	            }
            break;
        }
        a = a->next;
    }
	if (index <= mida)
		movs = index;
	else
		movs =  size - index;
	return (movs);
}
void	set_hops(p_stack *a,p_stack *b)
{
	int midb;
	int mov;
	int size;
	size = ft_lstsize(b);
	midb = (ft_lstsize(b) - 1) / 2;
	while (b)
	{
		if (b->index <= midb)
			mov = b->index + 1;
		else
			mov =  size - b->index + 1;
		mov = mov + movsa(a,b->content);
		b->movs = mov;
		b = b->next;
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
int		get_less_movs(p_stack *b)
{
	int index;
	int movs;
	movs = b->movs;
	while (b)
	{
		if (movs < b->movs)
			index = b->index;
		b = b->next;
	}
	printf("bm --> %d\n",movs);
	return index;
}
void	set_a(p_stack **a, int minmax)
{
	int size;
	int mida;
	int i;
	i = 0;
	size = ft_lstsize(*a);
	mida = (size - 1) / 2;
		if (minmax <= mida)
		{
			while (i < minmax)
			{
				rotate(a,'a');
				i++;
			}
		}
		else
		{
			while (i < size - minmax)
			{
				reverse_rotate(a,'a');
				i++;
			}
		}	 	
}
void	do_action(p_stack **a, char acc, char stat, int times)
{
	int i;
	i = 0;
	while (i < times)
	{
		if (acc == 'r' && stat == 'b')
			rotate(a,'a');
		else if (acc == 's' && stat == 'b')
			reverse_rotate(a,'a');
		i++;
	}
}
void	set_b(p_stack **a, p_stack **b, int midb)
{
	int  less;
	int size;
	size = ft_lstsize(*b);
	less = get_less_movs(*b);
	printf("less -> %d \n",less);
	set_a(a,minmax(*a,(*b)->content));
	printf("a --> %d\n",(*a)->content);
	if (less <= midb)
		do_action(b,'r','b',less);
	else
		do_action(b,'s','b',size - less);
	push_a(a,b);
}
void sort_big(p_stack **a, p_stack **b, data *info)
{
	p_stack *tmp;
	int max;
	int midb;

	tmp = *a;
	int i;
	set_len(a,info);
	set_pnp(*a);
	i = 0;
	max = get_max_len(*a);
	while (ft_lstsize(*a) > max)
	{
		if ((*a)->pnp == 0)
			push_b(b,a);
		else
			reverse_rotate(a,'a');
	}
	ft_index(*a);
	ft_index(*b);
	midb = (ft_lstsize(*b) - 1) / 2;
	set_hops(*a,*b);
	while (*b)
	{
		ft_index(*a);
		ft_index(*b);
		midb = (ft_lstsize(*b) - 1) / 2;
		set_b(a,b,midb);
	}
	
	
}
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
	sort_big(&stack_a,&stack_b,&info);
	 printf("sorted : %d\n",sorted(&stack_a));
	//  callen(4,info);
	//    sort_big(&stack_a,&stack_b,&info);
	//  set_hops(stack_a,stack_b);
	// printf("%d\n",minmax(stack_a,24));
	//   sort_big(&stack_a,&stack_b,info);
	// stack_b = stack_a;
	while (stack_a)
	{
		printf(" %d ",stack_a->content);
		stack_a = stack_a->next;
	}
	// // // stack_a = stack_b;
	// // printf("\nsize of b -> %d\n",ft_lstsize(stack_b));
	while (stack_b)
	{
		printf(" [%d] ",stack_b->content);
		stack_b = stack_b->next;
	}
}	