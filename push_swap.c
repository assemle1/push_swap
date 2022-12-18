/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:32:20 by astalha           #+#    #+#             */
/*   Updated: 2022/12/03 16:07:49 by astalha          ###   ########.fr       */
/*                  ≥                                                          */
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
int	main(int ac, char *av[])
{
	char *params;
	char **splparam;
	p_stack *stack_a;
	p_stack *stack_b;
	data	info;

	int	i;
	params = ft_strjoin(ac,av," ");
	info.args = ft_split(params, ' ');
	info.nbelem = count(info.args);
	info.arr = malloc(sizeof(long) * count(info.args));
	// stack_b = malloc(sizeof(p_stack) * count(info.args));
	make_arr(&info);
	if (!check(params) || !check_double(&info))
	{
		ft_putstr_fd("Error\n",2);
		return (0);
	}
	if (issorted(&info))
		return (0);
	link_args(&stack_a,info);
}