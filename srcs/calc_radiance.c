/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_radiance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:14:15 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/26 20:32:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	calc_radiance(
				t_rt *rt, t_ray *ray, t_object *object)
{
	double	radiance;

	radiance = 0;
	radiance += calc_ambient_radiance(rt);
	radiance += calc_diffuse_reflection_radiance(rt, ray, object);
	radiance /= 2.0;
	if (radiance < 0)
		radiance = 0;
	if (radiance >= 1)
		radiance = 1;
	return (radiance);
}
