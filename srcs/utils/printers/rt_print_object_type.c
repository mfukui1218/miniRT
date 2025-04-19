/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_object_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:23:41 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 01:23:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_object_type(const t_object_type *type)
{
	if (type == NULL)
		return ;
	if (*type == SPHERE)
		printf(BLUE "SPHERE\n" CLC);
	else if (*type == PLANE)
		printf(GREEN "PLANE\n" CLC);
	else if (*type == CYLINDER)
		printf(YELLOW "CYLINDER\n" CLC);
}
