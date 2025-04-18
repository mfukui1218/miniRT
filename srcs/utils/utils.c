/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:43 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 14:53:05 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_valid_condition(char **rt)
{
	if (has_one_info(rt, "C") != 1)
		return (false);
	if (has_one_info(rt, "A") != 1)
		return (false);
	if (has_one_info(rt, "L") != 1)
		return (false);
	if (has_object_info(rt) == 0)
		return (false);
	return (true);
}

size_t	skip_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

void	inclement_ij(size_t *i, size_t *j)
{
	(*i)++;
	(*j)++;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = ft_lstnew((void *)new);
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = ft_lstnew((void *)new);
}

t_list	*ft_lstnew(void *new)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = new;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}