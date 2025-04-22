/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:06:59 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 13:58:58 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_sphere(t_object *obj, char *line)
{
	size_t		j;
	t_sphere	*sphere;

	obj->type = SPHERE;
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (error_message(ALLOCATE), false);
	init_sphere(sphere);
	obj->object = sphere;
	j = skip_space(line) + 2;
	if (!skip_and_set(line, &j, &(sphere->position),
			(bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(line, &j, &(sphere->radius),
			(bool (*)(void *, char *, size_t *))set_radius))
		return (false);
	if (!skip_and_set(line, &j, &(sphere->color),
			(bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);
}
