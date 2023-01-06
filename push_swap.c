/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:30:13 by astalha           #+#    #+#             */
/*   Updated: 2023/01/06 17:41:56 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*initialise(int ac, char **av, t_data *info)
{
	char	*params;

	params = ft_strjoin(ac, av, " ");
	info->args = ft_split(params, ' ');
	info->nbelem = count(info->args);
	info->arr = malloc(sizeof(int) * count(info->args));
	if (!info->arr)
		return (NULL);
	make_arr(info);
	return (params);
}

int	main(int ac, char *av[])
{
	char	*params;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	info;

	params = initialise(ac, av, &info);
	if (!check(params) || !check_double(&info) || !params)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (issorted(&info))
		return (ft_putstr_fd("input sorted , please try again!", 2), 0);
	stack_a = link_args(&info);
	stack_b = NULL;
	ft_index(stack_a);
	if (info.nbelem <= 5)
		sort_small(&stack_a, &stack_b, &info);
	else
		sort_big(&stack_a, &stack_b, &info);
	free(info.arr);
	freealloc(info.args, count(info.args));
	free(params);
	ft_lstclear(&stack_a);
}
