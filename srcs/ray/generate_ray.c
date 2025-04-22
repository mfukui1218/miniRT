/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 16:23:45 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	generate_ray(t_rt *rt, size_t x, size_t y)
{
	t_ray				ray;
	float				fov_scale;
	t_camera_vectors	camera_vectors;
	float				u;
	float				v;

	fov_scale = tanf(rt->camera->fov * 0.5f * M_PI / 180.0f);
	ray.origin = rt->camera->position;
	camera_vectors.forward = vec_normalize(rt->camera->orientation);
	camera_vectors.right
		= vec_normalize(vec_cross((t_vector){0, 1, 0}, camera_vectors.forward));
	camera_vectors.up = vec_cross(camera_vectors.right, camera_vectors.forward);
	u = (2.0f * (x + 0.5f) / rt->screen.width - 1.0f)
		* rt->screen.aspect_ratio * fov_scale;
	v = (1.0f - 2.0f * (y + 0.5f) / rt->screen.height) * fov_scale;
	ray.direction = vec_normalize(vec_add3(
				vec_scale(camera_vectors.right, u),
				vec_scale(camera_vectors.up, v),
				camera_vectors.forward));
	return (ray);
}
