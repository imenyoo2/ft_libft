


#include "main.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
  // in case lst is NULL we can't derefrence it
  // TODO: maybe if new is NULL, we should just change *lst
  if (lst == NULL)
    return;
  new->next = *lst;
  *lst = new;
}
