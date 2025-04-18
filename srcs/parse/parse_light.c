/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:39:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 13:55:57 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_light(t_rt *rt)
{
	size_t	i;
	size_t	j;

	rt->light = malloc(sizeof(t_light));
	if (!rt->light)
		return (error_message(ALLOCATE), false);
	init_light(rt->light);
	i = find_line_str(rt->rt, "L");
	j = skip_space(rt->rt[i]) + 1;
	if (!skip_and_set(rt->rt[i], &j, &(rt->light->position), (bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(rt->rt[i], &j, &(rt->light->brightness), (bool (*)(void *, char *, size_t *))set_brightness))
		return (false);
	if (!skip_and_set(rt->rt[i], &j, &(rt->light->color), (bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);
}