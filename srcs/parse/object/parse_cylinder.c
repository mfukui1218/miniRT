/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:07:45 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 16:41:21 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_cylinder(t_object *obj, char *line)
{
	size_t		j;

	obj->type = CYLINDER;
	obj->object = malloc(sizeof(t_cylinder));
	if (!obj->object)
		return (error_message(ALLOCATE), false);
	init_cylinder(((t_cylinder *)(obj->object)));
	j = skip_space(line) + 2;
	if (!skip_and_set(line, &j, &(((t_cylinder *)(obj->object))->position),
		(bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(line, &j, &(((t_cylinder *)(obj->object))->orientation),
		(bool (*)(void *, char *, size_t *))set_vector))
		return (false);
	if (!skip_and_set(line, &j, &(((t_cylinder *)(obj->object))->radius),
		(bool (*)(void *, char *, size_t *))set_radius))
		return (false);
	if (!skip_and_set(line, &j, &(((t_cylinder *)(obj->object))->height),
		(bool (*)(void *, char *, size_t *))set_height))
		return (false);
	if (!skip_and_set(line, &j, &(((t_cylinder *)(obj->object))->color),
		(bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);
}
