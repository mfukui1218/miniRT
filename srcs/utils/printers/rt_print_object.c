/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:37:38 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 01:23:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_object(const t_object *obj)
{
	if (obj == NULL)
		return ;
	rt_print_str("type: ");
	rt_print_object_type(&obj->type);
	rt_print_indent(1);
	rt_print_str("object:\n");
	if (obj->type == SPHERE)
		rt_print_with_indent((t_print_func)rt_print_sphere, obj->object);
	else if (obj->type == PLANE)
		rt_print_with_indent((t_print_func)rt_print_plane, obj->object);
	else if (obj->type == CYLINDER)
		rt_print_with_indent((t_print_func)rt_print_cylinder, obj->object);
	rt_print_str("color: ");
	rt_print_color(&obj->color);
	rt_print_indent(-1);
}
