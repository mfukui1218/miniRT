/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 01:07:38 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_plane(t_ray ray, t_plane *plane, float *t)
{
	t_vector	axis;
	t_vector	oc;
	float		dot_product;
	t_vector	normal;

	dot_product = vec_dot(ray.direction, axis);
	if (fabs(dot_product) < 1e-6)
		return (false);
	normal = vec_normalize(plane->orientation);
	oc = vec_sub(ray.origin, plane->position);
	*t = -vec_dot(oc, normal) / dot_product;
	if (*t < 0.001f)
		return (false);
	if (vec_dot(vec_sub(ray.origin, plane->position), normal) > 0)
		*t = -(*t);
	return (true);
}
