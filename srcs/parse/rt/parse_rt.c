/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:15:03 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 21:08:52 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	init_mlx_window(t_rt *rt)
{
	rt->mlx = mlx_init();
	if (!rt->mlx)
		return (error_message(MLX), false);
	rt->win = mlx_new_window(rt->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "miniRT");
	if (!rt->win)
		return (error_message(WIN), false);
	mlx_string_put(rt->mlx, rt->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		LOAD_COLOR, "Loading...");
	rt->screen_image = rt_new_image(rt->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!rt->screen_image)
		return (error_message(ALLOCATE), false);
	return (true);
}

static bool	load_rt_file(t_rt *rt, char *file_name)
{
	if (!parse_txt(rt, file_name))
		return (false);
	if (!is_valid_condition(rt->rt))
		return (false);
	return (true);
}

static bool	parse_scene_elements(t_rt *rt)
{
	size_t	i;

	i = 0;
	while (rt->rt[i])
	{
		if (is_start_str(rt->rt[i], "C"))
			if (!parse_camera(rt))
				return (error_message(CAMERA), false);
		if (is_start_str(rt->rt[i], "A"))
			if (!parse_ambient(rt))
				return (error_message(AMBIENT), false);
		if (is_start_str(rt->rt[i], "L"))
			if (!parse_light(rt))
				return (error_message(LIGHT), false);
		i++;
	}
	return (true);
}

bool	parse_rt(t_rt *rt, char *file_name)
{
	if (!init_mlx_window(rt))
		return (false);
	if (!load_rt_file(rt, file_name))
		return (false);
	if (!parse_scene_elements(rt))
		return (false);
	if (!parse_object(rt))
		return (error_message(OBJECT), false);
	rt->screen.width = SCREEN_WIDTH;
	rt->screen.height = SCREEN_HEIGHT;
	rt->screen.aspect_ratio = (double)SCREEN_WIDTH / (double)SCREEN_HEIGHT;
	rt->screen.scale
		= 1.0f / (2.0f * tanf(rt->camera->fov / 2.0f * (M_PI / 180.0f)));
	return (true);
}
