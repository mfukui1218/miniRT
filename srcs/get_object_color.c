/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:12:48 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 21:19:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	get_object_color(const t_object *object)
{

	if (object->type == SPHERE)
		return (((t_sphere *)(object->object))->color);
	else if (object->type == PLANE)
		return (((t_plane *)(object->object))->color);
	else if (object->type == CYLINDER)
		return (((t_cylinder *)(object->object))->color);
	return ((((t_cylinder *)(object->object))->color));
}
