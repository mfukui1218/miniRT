/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:22 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 18:25:14 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_valid_condition(char **rt)
{
	if (!is_valid_camera(rt))
		return (false);
	if (!is_valid_ambient(rt))
		return (false);
	if (!is_valid_light(rt))
		return (false);
	if (!is_valid_object(rt))
		return (false);
	return (true);
}

bool	is_valid_camera(char **rt)
{
	size_t	i;
	size_t	j;

	if (has_one_info(rt, "C") != 1)
		return (false);
	i = find_line_str(rt, "C");
	j = skip_space(rt[i]) + 1;
	if (!parse_and_check(rt[i], &j, is_valid_coordinate))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_vector))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_coordinate))
		return (false);
	return (true);
}

bool	is_valid_ambient(char **rt)
{
	size_t	i;
	size_t	j;

	if (has_one_info(rt, "A") != 1)
		return (false);
	i = find_line_str(rt, "A");
	j = skip_space(rt[i]) + 1;
	if (!parse_and_check(rt[i], &j, is_valid_brightness))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_color))
		return (false);
	return (true);
}

bool	is_valid_light(char **rt)
{
	size_t	i;
	size_t	j;

	if (has_one_info(rt, "L") != 1)
		return (false);
	i = find_line_str(rt, "L");
	j = skip_space(rt[i]) + 1;
	if (!parse_and_check(rt[i], &j, is_valid_coordinate))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_brightness))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_color))
		return (false);
	return (true);
}

bool	is_valid_object(char **rt)
{
	size_t	i;

	i = 0;
	if (!has_object_info(rt))
		return (false);
	while (rt[i])
	{
		if (is_start_str(rt[i], "sp"))
			return (is_valid_sphere(rt[i]));
		if (is_start_str(rt[i], "pl"))
			return (is_valid_plane(rt[i]));
		if (is_start_str(rt[i], "cy"))
			return (is_valid_cylinder(rt[i]));
		i++;
	}
	return (true);
}
