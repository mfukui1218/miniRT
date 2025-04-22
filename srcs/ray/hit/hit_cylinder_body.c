/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_body.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:28:02 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 17:11:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	hit_cylinder_cap_top(t_ray ray, t_cylinder *cy, double *t)
{
	t_vector	axis;
	t_vector	center;
	double		denom;
	double		temp_t;
	t_vector	hit_point;

	axis = vec_normalize(cy->orientation);
	center = vec_add(cy->position, vec_scale(axis, cy->height));
	denom = vec_dot(ray.direction, axis);
	if (fabs(denom) < 1e-6f)
		return (false);
	temp_t = vec_dot(vec_sub(center, ray.origin), axis) / denom;
	if (temp_t < 0.001f)
		return (false);
	hit_point = vec_add(ray.origin, vec_scale(ray.direction, temp_t));
	if (vec_len(vec_sub(hit_point, center)) > cy->radius)
		return (false);
	*t = temp_t;
	return (true);
}

static bool	hit_cylinder_cap_bottom(t_ray ray, t_cylinder *cy, double *t)
{
	t_vector	axis;
	t_vector	center;
	double		denom;
	t_vector	hit_point;
	double		temp_t;

	axis = vec_normalize(cy->orientation);
	center = cy->position;
	denom = vec_dot(ray.direction, axis);
	if (fabs(denom) < 1e-6f)
		return (false);
	temp_t = vec_dot(vec_sub(center, ray.origin), axis) / denom;
	if (temp_t < 0.001f)
		return (false);
	hit_point = vec_add(ray.origin,
			vec_scale(ray.direction, temp_t));
	if (vec_len(vec_sub(hit_point, center)) > cy->radius + 1e-6f)
		return (false);
	*t = temp_t;
	return (true);
}

bool	hit_cylinder_caps(t_ray ray, t_cylinder *cy, double *t)
{
	double	t_top;
	double	t_bot;
	bool	hit;

	hit = false;
	if (hit_cylinder_cap_top(ray, cy, &t_top))
	{
		*t = t_top;
		hit = true;
	}
	if (hit_cylinder_cap_bottom(ray, cy, &t_bot))
	{
		if (!hit || t_bot < *t)
			*t = t_bot;
		hit = true;
	}
	return (hit);
}
