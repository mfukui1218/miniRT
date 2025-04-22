/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_radiance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:14:15 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 20:56:25 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_radiance	calc_ambient_radiance(const t_rt *rt)
{
	t_radiance	radiance;

	radiance = 0;
	if (rt->ambient)
		radiance = rt->ambient->brightness;
	return (radiance);
}

static t_radiance	calc_diffuse_reflection_radiance(
	const t_rt *rt, const t_ray *ray, const t_object *object)
{
	t_ray	normal_ray;

	if (is_shadow(rt, ray, object))
		return (0);
	normal_ray = generate_normal_ray(rt, ray, object);
	return (0);
}

t_radiance	calc_radiance(
				const t_rt *rt, const t_ray *ray, const t_object *object)
{
	t_radiance	radiance;

	radiance = 0;
	radiance += calc_ambient_radiance(rt);
	radiance += calc_diffuse_reflection_radiance(rt, ray, object);
	return (radiance);
}
