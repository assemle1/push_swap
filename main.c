#include "push_swap.h"
int		get_min_value(p_stack *a)
{
	p_stack *tmp;
	int min;
	min = a->content;

	tmp = a;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return min;
}
int		calmovsa(p_stack *a, int n)
{
	int last;
	
	last = get_min_value(a);
    while (a)
    {
        if (a->content > n)
        {
            last = a->content;
            while (a)
	            {
		            if(a->content > n && a->content < last)
			        last = a->content;
		                a = a->next;
	            }
            break;
        }
        a = a->next;
    }
	return last;	
}
int main()
{
    p_stack *head;
    head = ft_lstnew(429);
    head->next = ft_lstnew(441);
    head->next->next = ft_lstnew(2);
    head->next->next->next = ft_lstnew(3);
    puts("ok");
    printf("len --> %d\n", calmovsa(head,1));
}