/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:29:55 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 18:48:20 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_camera(t_rt *rt, char *line)
{
	int	i;

	rt->camera = malloc(sizeof(t_camera));
	if (!rt->camera)
		return (error_message(ALLOCATE), false);
	init_camera(rt->camera);
	i = 0;
	i += skip_space(line) + 1;
	i += skip_space(line + i);
	if (!parse_coordinate(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!set_vector(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!set_fov(rt, line, &i))
		return (false);
	return (true);
}
