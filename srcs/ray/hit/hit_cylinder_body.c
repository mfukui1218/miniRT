/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_body.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:28:02 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 16:35:00 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	hit_cylinder_cap_top(t_ray ray, t_cylinder *cy, float *t)
{
	t_vector	axis;
	t_vector	center;
	float		denom;
	float		temp_t;
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

static bool	hit_cylinder_cap_bottom(t_ray ray, t_cylinder *cy, float *t)
{
	t_vector	axis;
	t_vector	center;
	float		denom;
	t_vector	hit_point;
	float		temp_t;

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

bool	hit_cylinder_caps(t_ray ray, t_cylinder *cy, float *t)
{
	float	t_top;
	float	t_bot;
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
