/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:39:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 14:45:15 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_object(t_rt *rt)
{
	size_t		i;
	t_object	*obj;

	rt->object = NULL;
	i = 0;
	while (rt->rt[i])
	{
		if (is_start_str(rt->rt[i], "sp"))
		{
			obj = malloc(sizeof(t_object));
			if (!obj)
				return (error_message(ALLOCATE), false);
			init_object(obj);
			if (!parse_sphere(obj, rt->rt[i]))
				return (false);
			ft_lstadd_back(&rt->object, ft_lstnew(obj));
		}
		else if (is_start_str(rt->rt[i], "pl"))
		{
			obj = malloc(sizeof(t_object));
			if (!obj)
				return (error_message(ALLOCATE), false);
			init_object(obj);
			if (!parse_plane(obj, rt->rt[i]))
				return (false);
			ft_lstadd_back(&rt->object, ft_lstnew(obj));
		}
		else if (is_start_str(rt->rt[i], "cy"))
		{
			obj = malloc(sizeof(t_object));
			if (!obj)
				return (error_message(ALLOCATE), false);
			init_object(obj);
			if (!parse_cylinder(obj, rt->rt[i]))
				return (false);
			ft_lstadd_back(&rt->object, ft_lstnew(obj));
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
