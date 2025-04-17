/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:15:03 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 01:14:06 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_rt(t_rt *rt, char *file_name)
{
	size_t	i;

	// rt->mlx = mlx_init();
	// if (!rt->mlx)
	// 	return (error_message(MLX), false);
	// rt->win = mlx_new_window(rt->mlx, 800, 1000, "miniRT");
	// if (!rt->win)
	// 	return (error_message(WIN), false);
	if (!parse_txt(rt, file_name))
		return (false);
	if (!is_valid_condition(rt->rt))
		return (false);
	i = 0;
	while (rt->rt[i])
	{
		if (is_start_str(rt->rt[i], "C"))
			if (!parse_camera(rt))
				return (false);
		if (is_start_str(rt->rt[i], "A"))
			if (!parse_ambient(rt))
				return (false);
		if (is_start_str(rt->rt[i], "L"))
			if (!parse_light(rt))
				return (false);
		if (is_start_str(rt->rt[i], "sp"))
			if (!parse_object(rt))
				return (false);
		if (is_start_str(rt->rt[i], "pl"))
			if (!parse_object(rt))
				return (false);
		if (is_start_str(rt->rt[i], "cy"))
			if (!parse_object(rt))
				return (false);
		i++;
	}
	return (true);
}

bool	parse_txt(t_rt *rt, char *file_name)
{
	int	fd;
	size_t	i;

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

