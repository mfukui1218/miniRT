/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 01:17:09 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	generate_ray(t_rt *rt, size_t x, size_t y)
{
	t_ray		ray;
	float		fov_scale;
	t_vector	forward;
	t_vector	right;
	t_vector	up;

	fov_scale = tanf(rt->camera->fov / 2.0f * (M_PI / 180.0f));
	ray.origin = rt->camera->position;
	forward = vec_normalize(rt->camera->orientation);
	right = vec_normalize(vec_cross(forward, (t_vector){0, 1, 0}));
	up = vec_cross(right, forward);
	ray.direction = vec_add(
		vec_add(
			vec_scale(right, (x + 0.5f) * rt->screen.scale * fov_scale),
			vec_scale(up, (y + 0.5f) * rt->screen.scale * fov_scale)
		),
		forward
	);
	return (ray);
}		
