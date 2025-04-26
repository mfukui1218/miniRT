/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 15:42:40 by tookuyam         ###   ########.fr       */
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
		t_object **hit_obj, double *closest_t)
{
	t_list		*lst;
	t_object	*obj;
	double		t;
	bool		hit;
	bool		is_init;

	hit = false;
	lst = rt->object;
	is_init = false;
	while (lst)
	{
		obj = (t_object *)lst->content;
		if (hit_object(ray, obj, &t))
		{
			if (is_init == false || t < *closest_t)
			{
				*closest_t = t;
				*hit_obj = obj;
				is_init = true;
				hit = true;
			}
		}
		lst = lst->next;
	}
	return (hit);
}
