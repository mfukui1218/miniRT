/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generate_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:55:27 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 17:05:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rt_generate_color(const t_rt *rt, const t_ray *ray)
{
	t_color		draw_color;
	t_radiance	radiance;
	t_object	*hit_obj;
	int			color;

	hit_obj = get_hit_object(rt, ray);
	if (hit_obj == NULL)
		return (BG_COLOR);
	radiance = calc_radiance(rt, ray, hit_obj);
	draw_color = mul_color_radiance(get_object_color(hit_obj), radiance);
	color = get_color(&draw_color);
	return (color);
}
