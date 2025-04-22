/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 14:48:05 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_plane(t_ray ray, t_plane *plane, float *t)
{
	t_vector	axis;
	t_vector	oc;
	float		dot_product;

	axis = vec_normalize(plane->orientation);
	dot_product = vec_dot(ray.direction, axis);
	if (fabs(dot_product) < 1e-6)
		return (false);
	oc = vec_sub(plane->position, ray.origin);
	*t = vec_dot(oc, axis) / dot_product;
	if (*t < 0.001f)
		return (false);
	return (true);
}
