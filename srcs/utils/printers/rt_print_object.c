/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:37:38 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 01:09:13 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_object(const t_object *obj)
{
	if (obj == NULL)
		return ;
	rt_print_str("type: ");
	rt_print_object_type(&obj->type);
	rt_print_indent(ADD_INDENT);
	rt_print_str("object:\n");
	if (obj->type == SPHERE)
		rt_print_with_indent((t_print_func)rt_print_sphere, obj->object);
	else if (obj->type == PLANE)
		rt_print_with_indent((t_print_func)rt_print_plane, obj->object);
	else if (obj->type == CYLINDER)
		rt_print_with_indent((t_print_func)rt_print_cylinder, obj->object);
	rt_print_str("color: ");
	rt_print_indent(SUB_INDENT);
}
