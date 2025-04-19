/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:39:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:08:19 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	parse_and_add_object(t_rt *rt, char *line,
		bool (*parse_func)(t_object *, char *))
{
	t_list		*new;
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (!object)
		return (false);
	init_object(object);
	if (!parse_func(object, line))
	{
		free(object);
		return (false);
	}
	new = ft_lstnew((void *)object);
	if (!new)
	{
		free(object);
		return (false);
	}
	if (!rt->object)
		rt->object = new;
	else
		ft_lstadd_back(&(rt->object), new);
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
