/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_normal_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:58:33 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 20:59:25 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	generate_normal_ray(
			const t_rt *rt, const t_ray *ray, const t_object *object)
{
	t_ray		normal_ray;
	t_vector	hit_point;

	hit_point = vec_add(ray->origin, vec_scale(ray->direction, object->t));
	return (normal_ray);
}
