/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:25:33 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 16:25:36 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
