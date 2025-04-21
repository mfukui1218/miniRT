/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 01:11:44 by mfukui           ###   ########.fr       */
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

static bool	set_cylinder_quadratic(t_quadratic *q, t_vector dir, t_vector oc, t_cylinder *cylinder)
{
	t_vector d_proj;
	t_vector oc_proj;
	float radius;
	t_vector axis;

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

static bool hit_cylinder_caps(t_ray ray, t_cylinder *cylinder, float *t)
{
	t_vector	axis;
	float		dot_product;
	float		h;
	float		t_top;
	float		t_bot;
	bool		hit;

	axis = vec_normalize(cylinder->orientation);
	dot_product = vec_dot(ray.direction, axis);
	hit = false;
	if (fabs(dot_product) < 1e-6)
		return (false);
	h = cylinder->height - vec_dot(vec_sub(ray.origin, cylinder->position), axis);
	t_top = h / dot_product;
	if (t_top > 0.0f)
		hit = true;
	h = cylinder->height - vec_dot(vec_sub(ray.origin, cylinder->position), axis);
	t_bot = h / dot_product;
	if (t_bot > 0.0f)
		hit = true;
	if (!hit)
		return (false);
	if (t_top < t_bot)
		*t = t_top;
	else
		*t = t_bot;
	return (hit);
}

static bool hit_cylinder_body(t_ray ray, t_cylinder *cylinder, float *t)
{
	t_vector	oc;
	t_quadratic	quadratic;
	float		h;
	t_vector	hit;

	if (!set_cylinder_quadratic(&quadratic, ray.direction, oc, cylinder))
		return (false);
	*t = solve_quadratic(quadratic.a, quadratic.b, quadratic.discriminant);
	if (*t < 0.001f)
		return (false);
	hit = vec_add(ray.origin, vec_scale(ray.direction, *t));
	h = vec_dot(vec_sub(hit, cylinder->position), vec_normalize(cylinder->orientation));
	if (h < 0.0f || h > cylinder->height)
		return (false);
	return (true);
}

bool	hit_cylinder(t_ray ray, t_cylinder *cylinder, float *t)
{
	bool hit;

	hit = false;
	if (!hit_cylinder_body(ray, cylinder, t))
		hit = true;
	if (hit_cylinder_caps(ray, cylinder, t))
		hit = true;
	return (hit);
}
