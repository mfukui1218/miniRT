/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:39:32 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 18:48:46 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_object(t_rt *rt, char *line)
{
	int	i;

	rt->object = malloc(sizeof(t_object));
	if (!rt->object)
		return (error_message(ALLOCATE), false);
	init_object(rt->object);
	i = 0;
	i += skip_space(line) + 1;
	i += skip_space(line + i);
	if (!parse_coordinate(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!set_vector(rt, line, &i))
		return (false);
	i += skip_space(line + i);
	if (!set_diameter(rt, line, &i))
		return (false);
	return (true);
}
