
#include "main.h"

// TODO: not tested
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
  t_list *head;
  t_list *tmp;
  t_list *holder;

  head = malloc(sizeof(t_list));
  if (head == NULL)
    return (NULL);
  head->content = f(lst->content);
  head->next = NULL;
  lst = lst->next;
  holder = head;
  while (lst)
  {
    tmp = malloc(sizeof(t_list));
    if (tmp == NULL)
    {
      ft_lstclear(&head, del);
      return (NULL);
    }
    tmp->content = f(lst->content);
    tmp->next = NULL;
    holder->next = tmp;
    holder = tmp;
    lst = lst->next;
  }
  return (head);
}
