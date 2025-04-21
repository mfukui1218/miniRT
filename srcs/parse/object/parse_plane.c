/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:08:25 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/21 20:44:35 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_plane(t_object *obj, char *line)
{
	size_t	j;
	t_plane	*plane;

	obj->type = PLANE;
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (error_message(ALLOCATE), false);
	init_plane(plane);
	obj->object = plane;
	j = skip_space(line) + 2;
	if (!skip_and_set(line, &j, &(plane->position),
			(bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(line, &j, &(plane->orientation),
			(bool (*)(void *, char *, size_t *))set_vector))
		return (false);
	if (!skip_and_set(line, &j, &(plane->color),
			(bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);
}
