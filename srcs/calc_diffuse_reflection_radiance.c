/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_diffuse_reflection_radiance.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:07:17 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/25 03:41:48 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vector get_cylinder_normal(t_vector p, t_cylinder *cy)
{
	t_vector cp = vec_sub(p, cy->position);
	t_vector axis = vec_normalize(cy->orientation);
	double d = vec_dot(cp, axis);

	if (d < 1e-3)
		return vec_scale(axis, -1);
	else if (d > cy->height - 1e-3)
		return axis;
	else
		return vec_normalize(vec_sub(cp, vec_scale(axis, d)));
}

static t_vector get_normal_vector(t_object *object, t_vector intersection)
{
	if (object->type == SPHERE)
		return (vec_sub(intersection, ((t_sphere *)object->object)->position));
	else if (object->type == PLANE)
		return (((t_plane *)object->object)->orientation);
	else if (object->type == CYLINDER)
		return (get_cylinder_normal(intersection, (t_cylinder *)object->object));
	return ((t_vector){0});
}

static t_vector	get_intersection(t_rt *rt, t_ray *ray, t_object *object, double *t)
{
	t_vector	intersection;

	if (!hit_object_list(rt, *ray, &object, t))
		return ((t_vector){0});
	intersection = vec_add(ray->origin, vec_scale(ray->direction, *t));
	return (intersection);
}
double	calc_diffuse_reflection_radiance(
				t_rt *rt, t_ray *ray, t_object *object)
{
	t_vector	intersection;
	double		result;
	t_vector	light_dir;
	double		t;
	double		diff;

	intersection = get_intersection(rt, ray, object, &t);
	if (is_shadow(rt, ray, object))
		return (0);
	light_dir = vec_normalize(vec_sub(rt->light->position, get_intersection(rt, ray, object, &t)));
	diff = fmax(0.0, vec_dot(vec_normalize(get_normal_vector(object, intersection)), light_dir));
	result = diff * rt->light->brightness;
	return (result);
}
