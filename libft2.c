/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:38:12 by astalha           #+#    #+#             */
/*   Updated: 2023/01/06 17:30:02 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

static void	errorexit(void)
{
	ft_putstr_fd("You depassed the int MAX/MIN!", 2);
	exit(0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	n;
	long	signe;

	i = 0;
	n = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	if (n >= 2147483647 || n <= -2147483648)
		errorexit();
	return ((int)n * signe);
}
