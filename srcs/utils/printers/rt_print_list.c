/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:17:49 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 18:18:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_list(const t_list *lst, void (*f)(const void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		printf(" -> ");
		lst = lst->next;
	}
}
