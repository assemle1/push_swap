#include "push_swap.h"

void	calc_len(p_stack **a,int n ,int len)
{
	p_stack *tmp;
	tmp = *a;
	while(*a)
	{
		if ((*a)->content == n)
        {
			(*a)->len = len;
            *a = tmp;
            return ;
        }
		(*a) = (*a)->next;
	}
	*a = tmp;
}
int main()
{
    p_stack *head;
    head = ft_lstnew(5);
    head->next = ft_lstnew(8);
    head->next->next = ft_lstnew(6);
    head->next->next->next = ft_lstnew(4);
    puts("ok");
    calc_len(&head,6,4);
    printf("len --> %d\n", head->next->next->len);
}