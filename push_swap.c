/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:30:13 by astalha           #+#    #+#             */
/*   Updated: 2022/12/23 13:51:22 by astalha          ###   ########.fr       */
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
int		get_max(p_stack **a)
{
	p_stack *tmp;
	int max;
	max = 0;
	int index;
	tmp = *a;
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
void ft_index(p_stack **a)
{
	p_stack *tmp;
	int i;
	i = 0;
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
		
		max = get_max(a);
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
void 	sort_5(p_stack **a, p_stack **b)
{
	while (!sorted(a))
	{
		sort_3(a);
		sort_3(&((*a)->next->next));
	}
	
}
// void	sort(p_stack **a, p_stack **b, data info)
// {
// 	if (info.nbelem < 5)
        
// }
int	main(int ac, char *av[])
{
	char *params;
	char **splparam;
	p_stack *stack_a = NULL;
	p_stack *stack_b = NULL;
	data	info;

	int	i;
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
	 ft_index(&stack_a);
	 //rotate(&stack_a,'a');
	//  sort_3(&stack_a);
	 sort_5(&stack_a,&stack_b);
	// printf("%d\n",get_max(&stack_a));
	// stack_b = ft_lstnew(10);
	// stack_b->next = ft_lstnew(11);
	// stack_b->next->next = ft_lstnew(12);
	// stack_b->next->next->next = ft_lstnew(13);
	// rrr(&stack_a,&stack_b);
	
	while (stack_a)
	{
		printf(" %d ",stack_a->content);
		stack_a = stack_a->next;
	}
	
		
	// push_b(&stack_b,&stack_a);
	// 	printf("\nstack b -> %d ",stack_b->content);

	// printf("\n");

	// while (stack_b)
	// {
	// 	  printf("stack b -> %d ",stack_b->content);
	// 	stack_b = stack_b->next;
		
	// }
// 	// xit(1);
// 	 ft_lstclear(&stack_a);
// 	ft_lstclear(&stack_b);
// 	freealloc(info.args,0);
//  free(info.arr);
// 	free(info.args);
	// // printf("\n stackb -> %d\n",stack_b->next->next->content);


}	