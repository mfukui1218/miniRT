/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:15:03 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 14:36:20 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_rt(t_rt *rt, char *file_name)
{
	size_t	i;

	rt->mlx = mlx_init();
	if (!rt->mlx)
		return (error_message(ALLOCATE), false);
	rt->win = mlx_new_window(rt->mlx, 80, 100, "miniRT");
	if (!rt->win)
		return (error_message(ALLOCATE), false);
	if (!set_txt(rt, file_name))
		return (false);
	i = 0;
	while (rt->rt[i])
	{
		if (is_start_str(rt->rt[i], "C"))
			if (!set_camera(rt, rt->rt[i]))
				return (false);
		if (is_start_str(rt->rt[i], "A"))
			if (!set_ambient(rt, rt->rt[i]))
				return (false);
		if (is_start_str(rt->rt[i], "L"))
			if (!set_light(rt, rt->rt[i]))
				return (false);
		if (is_start_str(rt->rt[i], "sp"))
			if (!set_object(rt, rt->rt[i]))
				return (false);
		if (is_start_str(rt->rt[i], "pl"))
			if (!set_object(rt, rt->rt[i]))
				return (false);
		if (is_start_str(rt->rt[i], "cy"))
			if (!set_object(rt, rt->rt[i]))
				return (false);
		i++;
	}
	return (true);
}

bool	set_txt(t_rt *rt, char *file_name)
{
	int	fd;
	int	i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (error_message(OPEN), false);
	rt->rt = malloc(sizeof(char *) * MAX_TXT_HEIGHT + 1);
	if (!rt->rt)
		return (error_message(ALLOCATE), false);
	i = 0;
	while (1)
	{
		rt->rt[i] = get_next_line(fd);
		if (!rt->rt[i])
			break ;
		i++;
	}
	close(fd);
	return (true);
}

bool	set_camera(t_rt *rt, char *line)
{
	int	i;

	rt->camera = malloc(sizeof(t_camera));
	if (!rt->camera)
		return (error_message(ALLOCATE), false);
	init_camera(rt->camera);
	i = 0;
	i += skip_space(line) + 1;
	i += skip_space(line + i);
	if (!set_coordinate(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!set_vector(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!set_fov(rt, line, &i))
		return (false);
	return (true);
}

bool	set_ambient(t_rt *rt, char *line)
{
	int	i;

	rt->ambient = malloc(sizeof(t_color));
	if (!rt->ambient)
		return (error_message(ALLOCATE), false);
	init_ambient(rt->ambient);
	i = 0;
	i += skip_space(line) + 1;
	i += skip_space(line + i);
	if (!set_brightness(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!set_color(rt, line, &i))
		return (false);
	return (true);
}

bool	set_light(t_rt *rt, char *line)
{
	int	i;

	rt->light = malloc(sizeof(t_light));
	if (!rt->light)
		return (error_message(ALLOCATE), false);
	init_light(rt->light);
	i = 0;
	i += skip_space(line) + 1;
	i += skip_space(line + i);
	if (!set_position(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!set_brightness(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!set_color(rt, line, &i))
		return (false);
	return (true);
}
