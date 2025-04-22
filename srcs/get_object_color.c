/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:12:48 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 20:36:39 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	get_object_color(const t_object *object)
{
	t_color	obj_color;

	(void)object;
	init_color(&obj_color);
	if (object->type == SPHERE)
		obj_color = ((t_sphere *)(object->object))->color;
	else if (object->type == PLANE)
		obj_color = ((t_plane *)(object->object))->color;
	else if (object->type == CYLINDER)
		obj_color = ((t_cylinder *)(object->object))->color;
	return (obj_color);
}
