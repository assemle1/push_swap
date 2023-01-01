/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:30:13 by astalha           #+#    #+#             */
/*   Updated: 2023/01/01 22:09:56 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char *params;
	t_stack *stack_a;
	 t_stack *stack_b;
	t_data	info;
	
	params = ft_strjoin(ac,av," ");
	info.args = ft_split(params, ' ');
	info.nbelem = count(info.args);
	info.arr = malloc(sizeof(int) * count(info.args));
		if (!info.arr)
			return (0);
	make_arr(&info);
	if (!check(params) || !check_double(&info))
	{
		ft_putstr_fd("Error\n",2);
		return (0);
	}
	if (issorted(&info))
		return (0);
	 stack_a = link_args(&info);
	 stack_b = NULL;
	 ft_index(stack_a);
	 if (info.nbelem <= 5)
		sort_small(&stack_a,&stack_b,info);
	else
	 	sort_big(&stack_a,&stack_b,&info);
	 printf("sorted : %d\n",sorted(&stack_a));
	//  free(info.arr);
	 while (1);
	 
}	