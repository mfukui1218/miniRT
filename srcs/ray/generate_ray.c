/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 15:39:12 by mfukui           ###   ########.fr       */
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
	float		u;
	float		v;

	fov_scale = tanf(rt->camera->fov * 0.5f * M_PI / 180.0f);
	ray.origin = rt->camera->position;
	forward = vec_normalize(rt->camera->orientation);
	right = vec_normalize(vec_cross((t_vector){0, 1, 0}, forward));
	up = vec_cross(right, forward);
	u = (2.0f * (x + 0.5f) / rt->screen.width - 1.0f) * rt->screen.aspect_ratio * fov_scale;
	v = (1.0f - 2.0f * (y + 0.5f) / rt->screen.height) * fov_scale;
	ray.direction = vec_normalize(vec_add3(vec_scale(right, u),
		vec_scale(up, v), forward));
	return (ray);
}
