/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:28:55 by astalha           #+#    #+#             */
/*   Updated: 2022/12/29 19:07:20 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct mydata
{
    char **args;
    int *arr;
    int    nbelem;
}               data;

typedef struct s_stack
{
	struct s_stack	*next;
	int			    content;
    int             len;
    int             index;
    int              pnp;
    int              movs;
}	            p_stack;

int check(char *av);
void	freealloc(char **ptr, int index);
char	*ft_strjoin(int size, char **strs, char *sep);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char	*str);
int	ft_isdigit(int arg);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
int	ft_atoi(const char *str);
p_stack		*ft_lstnew(int content);
void		ft_lstadd_front(p_stack **lst, p_stack *new);
int			ft_lstsize(p_stack *lst);
p_stack		*ft_lstlast(p_stack *lst);
void		ft_lstadd_back(p_stack **lst, p_stack *new);
void		ft_lstiter(p_stack *lst, void (*f)(void *));
p_stack		*ft_lstmap(p_stack *lst, void *(*f)(void *), void (*del)(void *));
int check_double(data *info);
int issorted(data *info);
void	swap(p_stack *leftnode, p_stack *rightnode, char stack);
void    ss(p_stack *a, p_stack *b);
void    push_b(p_stack **b, p_stack **a);
void    push_a(p_stack **a, p_stack **b);
void    rotate(p_stack **a, char index);
void    rr(p_stack  **a, p_stack **b);
void    reverse_rotate(p_stack  **a, char index);
void    rrr(p_stack **a, p_stack **b);
int     ft_lstsize(p_stack *lst);
void    ft_lstclear(p_stack **lst);

#endif
