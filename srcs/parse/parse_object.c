/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:39:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 15:00:35 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_and_add_object(t_rt *rt, char *line,
	bool (*parse_func)(t_object *, char *))
{
	t_object *obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (error_message(ALLOCATE), false);
	init_object(obj);
	if (!parse_func(obj, line))
		return (false);
	ft_lstadd_back(&rt->object, ft_lstnew(obj));
	return (true);
}

bool	parse_object(t_rt *rt)
{
	size_t	i;

	rt->object = NULL;
	i = 0;
	while (rt->rt[i])
	{
		if (is_start_str(rt->rt[i], "sp"))
		{
			if (!parse_and_add_object(rt, rt->rt[i], parse_sphere))
				return (false);
		}
		else if (is_start_str(rt->rt[i], "pl"))
		{
			if (!parse_and_add_object(rt, rt->rt[i], parse_plane))
				return (false);
		}
		else if (is_start_str(rt->rt[i], "cy"))
		{
			if (!parse_and_add_object(rt, rt->rt[i], parse_cylinder))
				return (false);
		}
		i++;
	}
	return (true);
}

bool	parse_sphere(t_object *obj, char *line)
{
	size_t	j;
	
	j = skip_space(line) + 2;
	if (!skip_and_set(line, &j, &(obj->position), (bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(line, &j, &(obj->radius), (bool (*)(void *, char *, size_t *))set_radius))
		return (false);
	if (!skip_and_set(line, &j, &(obj->color), (bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);
}

bool	parse_plane(t_object *obj, char *line)
{
	size_t	j;

	j = skip_space(line) + 2;
	if (!skip_and_set(line, &j, &(obj->position), (bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(line, &j, &(obj->orientation), (bool (*)(void *, char *, size_t *))set_vector))
		return (false);
	if (!skip_and_set(line, &j, &(obj->color), (bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);
}

bool	parse_cylinder(t_object *obj, char *line)
{
	size_t	j;

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
