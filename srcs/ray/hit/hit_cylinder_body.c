/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_caps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 17:11:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static	bool	set_cylinder_quadratic(t_quadratic *q,
	t_vector dir, t_vector oc, t_cylinder *cylinder)
{
	t_vector	d_proj;
	t_vector	oc_proj;
	double		radius;
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

bool	hit_cylinder_body(t_ray ray, t_cylinder *cylinder, double *t)
{
	t_vector	oc;
	t_quadratic	quadratic;
	double		h;
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
