/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_obj_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:40:31 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 22:24:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_obj_type(const t_object_type *type)
{
	if (type == NULL)
		return ;
	if (*type == SPHERE)
		printf("SPHERE");
	else if (*type == PLANE)
		printf("PLANE");
	else if (*type == CYLINDER)
		printf("CYLINDER");
}
