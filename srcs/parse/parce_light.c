/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:39:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 18:53:45 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


bool	parse_light(t_rt *rt, char *line)
{
	int	i;

	rt->light = malloc(sizeof(t_light));
	if (!rt->light)
		return (error_message(ALLOCATE), false);
	init_light(rt->light);
	i = 0;
	i += skip_space(line) + 1;
	i += skip_space(line + i);
	if (!parse_position(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!parse_brightness(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!parse_color(rt, line, &i))
		return (false);
	return (true);
}
