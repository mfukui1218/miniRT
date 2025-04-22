/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 14:29:10 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	solve_quadratic(float a, float b, float discriminant)
{
	float	t1;
	float	t2;

	if (discriminant < 0)
		return (-1.0f);
	t1 = (-b - sqrtf(discriminant)) / (2.0f * a);
	t2 = (-b + sqrtf(discriminant)) / (2.0f * a);
	if (t1 > 0.001f)
		return (t1);
	else if (t2 > 0.001f)
		return (t2);
	return (-1.0f);
}

static bool	set_sphere_quadratic(t_quadratic *q,
		t_vector dir, t_vector oc, t_sphere *sphere)
{
	float	radius;

	radius = sphere->radius;
	q->a = vec_dot(dir, dir);
	q->b = 2.0f * vec_dot(oc, dir);
	q->c = vec_dot(oc, oc) - radius * radius;
	q->discriminant = q->b * q->b - 4.0f * q->a * q->c;
	if (q->discriminant < 1e-6f)
		return (false);
	return (true);
}

bool	hit_sphere(t_ray ray, t_sphere *sphere, float *t)
{
	t_vector	oc;
	t_quadratic	quadratic;

	oc = vec_sub(ray.origin, sphere->position);
	if (!set_sphere_quadratic(&quadratic, ray.direction, oc, sphere))
		return (false);
	*t = solve_quadratic(quadratic.a, quadratic.b, quadratic.discriminant);
	if (*t < 0.001f)
		return (false);
	return (true);
}
