/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 01:08:48 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_ray(t_rt *rt)
{
	size_t	x;
	size_t	y;
	t_color	color;
	t_ray	ray;
	
	x = 0;
	while(x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			ray = generate_ray(rt, x, y);
			color = get_hit_color(rt, ray);
			if (color.r == 0 && color.g == 0 && color.b == 0)
				rt_mlx_pixel_put(rt->screen_image, x, y, BG_COLOR);
			else
				rt_mlx_pixel_put(rt->screen_image, x, y,
					(color.r << 16) | (color.g << 8) | color.b);
			y++;
		}
		x++;
	}
	return (true);
}
