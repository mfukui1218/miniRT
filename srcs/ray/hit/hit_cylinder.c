/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 15:37:27 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	solve_quadratic(float a, float b, float discriminant)
{
	float	t1;
	float	t2;

	t1 = (-b - sqrtf(discriminant)) / (2.0f * a);
	t2 = (-b + sqrtf(discriminant)) / (2.0f * a);
	if (t1 > 0.001f)
		return (t1);
	else if (t2 > 0.001f)
		return (t2);
	return (-1.0f);
}

static	bool	set_cylinder_quadratic(t_quadratic *q, t_vector dir, t_vector oc, t_cylinder *cylinder)
{
	t_vector	d_proj;
	t_vector	oc_proj;
	float		radius;
	t_vector	axis;

	radius = cylinder->radius;
	axis = vec_normalize(cylinder->orientation);
	d_proj = vec_sub(dir, vec_scale(axis, vec_dot(dir, axis)));
	oc_proj = vec_sub(oc, vec_scale(axis, vec_dot(oc, axis)));
	q->a = vec_dot(d_proj, d_proj);
	q->b = 2.0f * vec_dot(d_proj, oc_proj);
	q->c = vec_dot(oc_proj, oc_proj) - radius * radius;
	q->discriminant = q->b * q->b - 4.0f * q->a * q->c;
	return (q->discriminant >= 0);
}

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

static bool	hit_cylinder_caps(t_ray ray, t_cylinder *cy, float *t)
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


static	bool	hit_cylinder_body(t_ray ray, t_cylinder *cylinder, float *t)
{
	t_vector	oc;
	t_quadratic	quadratic;
	float		h;
	t_vector	hit;

	oc = vec_sub(ray.origin, cylinder->position);
	if (!set_cylinder_quadratic(&quadratic, ray.direction, oc, cylinder))
		return (false);
	*t = solve_quadratic(quadratic.a, quadratic.b, quadratic.discriminant);
	if (*t < 0.001f)
		return (false);
	hit = vec_add(ray.origin, vec_scale(ray.direction, *t));
	h = vec_dot(vec_sub(hit, cylinder->position),
			vec_normalize(cylinder->orientation));
	if (h < -0.001f || h > cylinder->height + 0.001f)
		return (false);
	return (true);
}

bool	hit_cylinder(t_ray ray, t_cylinder *cylinder, float *t)
{
	bool	hit;
	float	t_body;
	float	t_caps;

	hit = false;
	if (hit_cylinder_body(ray, cylinder, &t_body))
	{
		*t = t_body;
		hit = true;
	}
	if (hit_cylinder_caps(ray, cylinder, &t_caps))
	{
		if (!hit || t_caps < *t)
			*t = t_caps;
		hit = true;
	}
	return (hit);
}
