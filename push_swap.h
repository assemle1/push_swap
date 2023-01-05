/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:28:55 by astalha           #+#    #+#             */
/*   Updated: 2023/01/05 20:08:16 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
    char **args;
    int *arr;
    int    nbelem;
}               t_data;

typedef struct s_stack
{
	struct s_stack	*next;
	int			    content;
    int             len;
    int             index;
    int              pnp;
    int              movs;
}	            t_stack;

void	do_double(t_stack **a, t_stack **b, int acc, int times);
void	do_rr(t_stack **a, t_stack **b, int less, int minmax);
void	do_rrr(t_stack **a, t_stack **b, int less, int minmax, int size_a, int size_b);
void	do_action(t_stack **b, int acc, int times);
void	a_set(t_stack **a, int minmax);
int check(char *av);
int check_double(t_data *info);
int issorted(t_data *info);
void    ft_lstclear(t_stack **lst);
void	freealloc(char **ptr, int index);
char	**ft_split(char const *s, char c);
void	swap(t_stack *leftnode, t_stack *rightnode, char stack);
void    ss(t_stack *a, t_stack *b);
void    push_a(t_stack **a, t_stack **b);
void    push_b(t_stack **b, t_stack **a);
void    rotate(t_stack **a, char index);
void    rr(t_stack  **a, t_stack **b);
void    reverse_rotate(t_stack  **a, char index);
void    rrr(t_stack **a, t_stack **b);
t_stack	*link_args(t_data	*info);
void make_arr(t_data *info);
int	count(char *str[]);
int sorted(t_stack **a);
int		get_min_value(t_stack *a);
int		get_min_index(t_stack *a);
int		get_max(t_stack *a);
void ft_index(t_stack *a);
void	sort_3(t_stack **a);
void	push_min(t_stack **a, t_stack **b, t_data *info);
void 	sort_small(t_stack **a, t_stack **b, t_data *info);
void 	lenght(t_data *info, int *j, int *len ,int *last);
int	callen(int n, t_data *info);
int		minmax(t_stack *a, int n);
void 	setlast(t_stack *a,int *last, int *index);
int		movsa(t_stack *a, int n);
void	set_hops(t_stack *a,t_stack *b);
void set_len(t_stack **a, t_data *info);
int 	getlessvalue(t_stack *b,int less);
void	pushsort(t_stack **a, t_stack **b, int midb);
void	push_back(t_stack **a, t_stack **b);
void sort_big(t_stack **a, t_stack **b, t_data *info);
int		get_less_movs(t_stack *b);
int		get_max_len(t_stack *a);
void pnp(t_stack **tmp, t_stack *a, int *last);
void	set_pnp(t_stack *a);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int     ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
int	ft_isdigit(int arg);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *src);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char	*str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_atoi(const char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
void	amovs(t_stack **a, int minmax, int mida, int size_a);
void	bmovs(t_stack **b, int less, int midb,int size_b);
void	do_movs(t_stack **a, t_stack **b, int less, int size_b, int midb, int minmax);

#endif
