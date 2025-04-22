/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_radiance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:14:15 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 16:57:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_radiance	calc_radiance(
				const t_rt *rt, const t_ray *ray, const t_object *object)
{
	t_radiance	radiance;

	radiance = 0;
	radiance += calc_ambient_radiance(rt);
	radiance += calc_diffuse_reflection_radiance(rt, ray, object);
	return (radiance);
}
