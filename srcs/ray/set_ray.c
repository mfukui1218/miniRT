/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 15:39:53 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_ray(t_rt *rt)
{
	size_t	x;
	size_t	y;
	t_color	color;
	t_ray	ray;
	int		rgb;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			ray = generate_ray(rt, x, y);
			color = get_hit_color(rt, ray);
			rgb = (color.r << 16) | (color.g << 8) | color.b;
			rt_mlx_pixel_put(rt->screen_image, x, SCREEN_HEIGHT - y - 1, rgb);
			y++;
		}
		x++;
	}
	return (true);
}
