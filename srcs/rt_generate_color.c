/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generate_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:55:27 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/27 16:12:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	div_color(t_color c1, double div);

int	rt_generate_color(t_rt *rt, t_ray *ray)
{
	t_color		draw_color;
	t_object	*hit_obj;
	int			color;

	hit_obj = get_hit_object(rt, ray);
	if (hit_obj == NULL)
		return (BG_COLOR);
	draw_color = add_color(
			calc_color(calc_ambient_radiance(rt), rt->ambient->color, hit_obj),
			calc_color(calc_diffuse_reflection_radiance(rt, ray, hit_obj),
				rt->light->color, hit_obj));
	draw_color = div_color(draw_color, 2);
	color = get_color(&draw_color);
	return (color);
}

static t_color	div_color(t_color c1, double div)
{
	c1.r /= div;
	c1.g /= div;
	c1.b /= div;
	return (c1);
}
