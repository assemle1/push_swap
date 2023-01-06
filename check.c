/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:40:51 by astalha           #+#    #+#             */
/*   Updated: 2023/01/06 15:32:30 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == 32)
			i++;
		else if (av[i - 1] == 32 && (av[i] == '-' || av[i] == '+'))
		{
			i++;
			if (!ft_isdigit(av[i]))
				return (0);
		}
		else if (!ft_isdigit(av[i]))
			return (0);
		else
			i++;
	}
	return (1);
}

int	check_double(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->nbelem)
	{
		j = 0;
		while (j < info->nbelem)
		{
			if (i != j && info->arr[i] == info->arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	issorted(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->nbelem)
	{
		j = i + 1;
		while (j < info->nbelem)
		{
			if (info->arr[i] > info->arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*plst;

	if (!lst)
		return ;
	plst = *lst;
	while (plst != NULL)
	{
		free(plst);
		plst = plst->next;
	}
	*lst = NULL;
}
