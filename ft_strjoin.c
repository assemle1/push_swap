/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:26:43 by astalha           #+#    #+#             */
/*   Updated: 2022/12/15 16:48:05 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cal_len(char **strs, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		k += j;
		i++;
	}
	return (k);
}

int	cal_lensep(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		i++;
	}
	return (i);
}

char	*cpy(char *str, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		l;
	char	*str;
	char	*save;
	int		i;

	if (size == 0)
		return (malloc(1));
	i = 1;
	l = cal_len(strs, size) + cal_lensep(sep) * (size - 1) + 1;
	str = malloc(l - ft_strlen(strs[0]));
	save = str;
	while (i < size)
	{
		cpy(str, strs[i]);
		str += cal_lensep(strs[i]);
		if (i != size - 1)
		{
			cpy(str, sep);
			str += cal_lensep(sep);
		}
		i++;
	}
	*str = 0;
	return (save);
}
