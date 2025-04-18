/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:39:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 14:02:59 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_object(t_rt *rt)
{
	size_t		i;

	rt->object = malloc(sizeof(t_object));
	if (!rt->object)
		return (error_message(ALLOCATE), false);
	rt->object->content = malloc(sizeof(t_object));
	if (!rt->object->content)
		return (error_message(ALLOCATE), false);
	init_object((t_object *)(rt->object->content));
	i = 0;
	while (rt->rt[i])
	{
		if (is_start_str(rt->rt[i], "sp"))
			if (!parse_sphere(rt, rt->rt[i]))
				return (false);
		if (is_start_str(rt->rt[i], "pl"))
			if (!parse_plane(rt, rt->rt[i]))
				return (false);
		if (is_start_str(rt->rt[i], "cy"))
			if (!parse_cylinder(rt, rt->rt[i]))
				return (false);
		i++;
	}
	return (true);
}

bool	parse_sphere(t_rt *rt, char *line)
{
	size_t	j;
	t_object	*obj;
	
	obj = (t_object *)(rt->object->content);
	j = skip_space(line) + 2;
	if (!skip_and_set(line, &j, &(obj->position), (bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(line, &j, &(obj->radius), (bool (*)(void *, char *, size_t *))set_radius))
		return (false);
	if (!skip_and_set(line, &j, &(obj->color), (bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);
}

bool	parse_plane(t_rt *rt, char *line)
{
	size_t	j;
	t_object	*obj;

	obj = (t_object *)(rt->object->content);
	j = skip_space(line) + 2;
	if (!skip_and_set(line, &j, &(obj->position), (bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(line, &j, &(obj->orientation), (bool (*)(void *, char *, size_t *))set_vector))
		return (false);
	if (!skip_and_set(line, &j, &(obj->color), (bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);
}

bool	parse_cylinder(t_rt *rt, char *line)
{
	size_t	j;
	t_object	*obj;

	obj = (t_object *)(rt->object->content);
	j = skip_space(line) + 2;
	if (!skip_and_set(line, &j, &(obj->position), (bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(line, &j, &(obj->orientation), (bool (*)(void *, char *, size_t *))set_vector))
		return (false);
	if (!skip_and_set(line, &j, &(obj->radius), (bool (*)(void *, char *, size_t *))set_radius))
		return (false);
	if (!skip_and_set(line, &j, &(obj->height), (bool (*)(void *, char *, size_t *))set_height))
		return (false);
	if (!skip_and_set(line, &j, &(obj->color), (bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);
}
