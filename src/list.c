#include "so_long.h"

t_node *new_list(int x, int y)
{
	t_node *next;

	next = malloc(sizeof(t_node));
	next->x = x;
	next->y = y;
	next->next = NULL;
	next->prev = NULL;
	return (next);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node *prev;
	prev = (*lst);
	if (lst && *lst)
	{
		while (prev->next != NULL)
			prev = prev->next;
		new->prev = prev;
		prev->next = new;
	}
	else if (lst)
		*lst = new;
}
void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstremove_back(t_node *lst)
{
	t_node *last;

	last = ft_lstlast(lst);
	if (last == lst)
	{
		free(lst);
		return ;
	}
	last->prev->next = NULL;
	free(last);
}