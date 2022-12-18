/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:34:59 by astalha           #+#    #+#             */
/*   Updated: 2022/12/15 16:35:30 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen (s))
		return (ft_strdup (""));
	if (len > ft_strlen (s))
		len = ft_strlen (s);
	ptr = malloc (len + 1);
	if (!ptr)
		return (NULL);
	while (s[i] && i < len)
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = 0;
	return (ptr);
}
