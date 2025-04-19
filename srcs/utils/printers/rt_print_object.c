/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:37:38 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 22:30:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_object(const t_object *obj)
{
	if (obj == NULL)
		return ;
	printf("{\n");
	printf("	type: ");
	rt_print_obj_type(&obj->type);
	printf("\n");
	printf("	object: ");
	if (obj->type == SPHERE)
		rt_print_sphere(obj->object);
	else if (obj->type == PLANE)
		rt_print_plane(obj->object);
	else if (obj->type == CYLINDER)
		rt_print_cylinder(obj->object);
	printf("	color: ");
	rt_print_color(&obj->color);
	printf("\n");
	printf("}\n");
}
