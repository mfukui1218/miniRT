/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:31 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 14:44:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_ray(t_rt *rt)
{
	size_t		x;
	size_t		y;
	int			color;
	t_ray		ray;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			ray = generate_ray(rt, x, y);
			color = rt_generate_color(rt, &ray);
			rt_mlx_pixel_put(rt->screen_image, x, SCREEN_HEIGHT - y - 1, color);
			y++;
		}
		x++;
	}
	return (true);
}
