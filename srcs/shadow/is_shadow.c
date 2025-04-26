/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:05:34 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/26 17:08:34 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool		hit_object(t_ray ray, t_object *object, double *t);
static bool		is_hit_one_object(t_rt *rt, t_ray *ray);
static t_ray	rt_generate_shadow_ray(
					t_vector *from, t_vector *to);

bool	is_shadow(t_rt *rt, t_ray *ray, t_object *object)
{
	t_vector	intersec_vec;
	t_ray		shadow_ray;
	double		obj_len;

	hit_object(*ray, (t_object *)object, &obj_len);
	intersec_vec.x = ray->origin.x + obj_len * ray->direction.x;
	intersec_vec.y = ray->origin.y + obj_len * ray->direction.y;
	intersec_vec.z = ray->origin.z + obj_len * ray->direction.z;
	shadow_ray = rt_generate_shadow_ray(&intersec_vec, &rt->light->position);
	return (is_hit_one_object(rt, &shadow_ray));
}

static t_ray	rt_generate_shadow_ray(t_vector *from, t_vector *to)
{
	double	epsilon;
	t_ray	ret_ray;

	epsilon = 1.0 / 512.0;
	ret_ray.direction = vec_normalize(vec_sub(*to, *from));
	ret_ray.origin.x = from->x + epsilon * ret_ray.direction.x;
	ret_ray.origin.y = from->y + epsilon * ret_ray.direction.y;
	ret_ray.origin.z = from->z + epsilon * ret_ray.direction.z;
	return (ret_ray);
}

static bool	is_hit_one_object(
				t_rt *rt, t_ray *ray)
{
	t_list		*lst;
	t_object	*obj;
	double		closest_t;
	double		light_len;
	double		epsilon;

	epsilon = 1 / 512.0;
	light_len = vec_len(vec_sub(ray->origin, rt->light->position));
	lst = rt->object;
	while (lst)
	{
		obj = (t_object *)lst->content;
		if (hit_object(*ray, obj, &closest_t)
			&& closest_t < light_len)
			return (true);
		lst = lst->next;
	}
	return (false);
}

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
