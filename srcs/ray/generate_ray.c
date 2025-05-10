/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/27 15:34:36 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vector	get_camera_direction(t_camera_vectors vectors,
		double u, double v)
{
	return (vec_normalize(vec_add3(
				vec_scale(vectors.right, u),
				vec_scale(vectors.up, v),
				vectors.forward)));
}

static t_ray	generate_ray_180_fov(t_rt *rt, size_t x,
		size_t y, t_camera_vectors vectors)
{
	t_ray	ray;
	double	u;
	double	v;

	u = (2.0 * (x + 0.5) / rt->screen.width - 1.0)
		* rt->screen.aspect_ratio * TAN_MAX;
	v = (1.0 - 2.0 * (y + 0.5) / rt->screen.height);
	ray.origin = rt->camera->position;
	ray.direction = get_camera_direction(vectors, u, v);
	return (ray);
}

t_ray	generate_ray(t_rt *rt, size_t x, size_t y)
{
	t_ray				ray;
	double				fov_scale;
	t_camera_vectors	camera_vectors;
	double				u;
	double				v;

	ray.origin = rt->camera->position;
	camera_vectors.forward = vec_normalize(rt->camera->orientation);
	camera_vectors.right
		= vec_normalize(vec_cross((t_vector){0, 1, 0}, camera_vectors.forward));
	camera_vectors.up = vec_cross(camera_vectors.right, camera_vectors.forward);
	if (rt->camera->fov == 180.0f)
		ray = generate_ray_180_fov(rt, x, y, camera_vectors);
	else
	{
		fov_scale = tanf(rt->camera->fov * 0.5f * M_PI / 180.0f);
		u = (2.0f * (x + 0.5f) / rt->screen.width - 1.0f)
			* rt->screen.aspect_ratio * fov_scale;
		v = (1.0f - 2.0f * (y + 0.5f) / rt->screen.height) * fov_scale;
		ray.direction = vec_normalize(vec_add3(
					vec_scale(camera_vectors.right, u),
					vec_scale(camera_vectors.up, v),
					camera_vectors.forward));
	}
	return (ray);
}
