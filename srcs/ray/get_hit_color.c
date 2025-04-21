/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 01:14:30 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	hit_object(t_ray ray, t_object *object, float *t)
{
	if (object->type == SPHERE)
		return (hit_sphere(ray, (t_sphere *)(object->object), t));
	else if (object->type == PLANE)
		return (hit_plane(ray, (t_plane *)(object->object), t));
	else if (object->type == CYLINDER)
		return (hit_cylinder(ray, (t_cylinder *)(object->object), t));
	return (false);
}

static bool	hit_object_list(t_rt *rt, t_ray ray, t_object **hit_obj, float *closest_t)
{
	t_list		*lst;
	t_object	*obj;
	float		t;
	bool		hit;

	*closest_t = FLT_MAX;
	hit = false;
	lst = rt->object;
	while (lst)
	{
		obj = (t_object *)lst->content;
		if (hit_object(ray, obj, &t))
		{
			if (t < *closest_t)
			{
				*closest_t = t;
				*hit_obj = obj;
				hit = true;
			}
		}
		lst = lst->next;
	}
	return (hit);
}

t_color get_hit_color(t_rt *rt, t_ray ray)
{
	t_object	*hit_obj;
	float		closest_t;

	if (hit_object_list(rt, ray, &hit_obj, &closest_t))
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
