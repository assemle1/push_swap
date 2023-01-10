/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:30:13 by astalha           #+#    #+#             */
/*   Updated: 2023/01/10 23:05:59 by astalha          ###   ########.fr       */
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
	make_arr(info, params);
	return (params);
}

void	to_free(t_data *info, char *params, t_stack **stack_a)
{
	free(info->arr);
	freealloc(info->args, count(info->args));
	if (params)
		free(params);
	if (stack_a)
		ft_lstclear(stack_a);
}

int	main(int ac, char *av[])
{
	char	*params;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	info;

	if (ac == 1)
		return (0);
	params = initialise(ac, av, &info);
	if (!check(params) || !check_double(&info) || !params)
		return (to_free(&info, params, NULL), errorexit(), 0);
	if (issorted(&info))
		return (to_free(&info, params, NULL), 0);
	stack_a = link_args(&info);
	stack_b = NULL;
	ft_index(stack_a);
	if (info.nbelem <= 5)
		sort_small(&stack_a, &stack_b, &info);
	else
		sort_big(&stack_a, &stack_b, &info);
	to_free(&info, params, &stack_a);
}
