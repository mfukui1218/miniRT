/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_diffuse_reflection_radiance.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:07:17 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 22:21:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_radiance	calc_diffuse_reflection_radiance(
				const t_rt *rt, const t_ray *ray, const t_object *object)
{
	t_ray	normal_ray;

	if (is_shadow(rt, ray, object))
		return (0);
	normal_ray = generate_normal_ray(rt, ray, object);
	return (1);
}
