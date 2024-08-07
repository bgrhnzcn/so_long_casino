#include "so_long.h"

t_node *new_list(int x, int y)
{
	t_node *next;

	next = malloc(sizeof(t_node));
	next->x = x;
	next->y = y;
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
	if (lst && *lst)
		ft_lstlast(*lst)->next = new;
	else if (lst)
		*lst = new;
}
void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}