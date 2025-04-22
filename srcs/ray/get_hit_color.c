/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 20:26:17 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	get_hit_color(t_rt *rt, t_ray ray)
{
	t_object	*hit_obj;

	if (hit_object_list(rt, ray, &hit_obj))
	{
		if (hit_obj->type == SPHERE)
			return (((t_sphere *)(hit_obj->object))->color);
		else if (hit_obj->type == PLANE)
			return (((t_plane *)(hit_obj->object))->color);
		else if (hit_obj->type == CYLINDER)
			return (((t_cylinder *)(hit_obj->object))->color);
	}
	return ((t_color){0, 0, 0});
}
