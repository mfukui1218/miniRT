/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:24:52 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 20:25:28 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	hit_object(t_ray ray, t_object *object, double *t)
{
	if (object->type == SPHERE)
		return (hit_sphere(ray, (t_sphere *)(object->object), t));
	else if (object->type == PLANE)
		return (hit_plane(ray, (t_plane *)(object->object), t));
	else if (object->type == CYLINDER)
		return (hit_cylinder(ray, (t_cylinder *)(object->object), t));
	return (false);
}

bool	hit_object_list(t_rt *rt, t_ray ray,
		t_object **hit_obj)
{
	t_list		*lst;
	t_object	*obj;
	double		t;
	bool		hit;
	double		*closest_t;

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
