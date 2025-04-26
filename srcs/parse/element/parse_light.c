/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:39:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 17:13:35 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	set_color_light(void *color, char *str, size_t *j)
{
	t_color	*color_f;

	color_f = (t_color *)color;
	color_f->r = ft_atoi(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	color_f->g = ft_atoi(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	color_f->b = ft_atoi(&str[*j]);
	if (!checklast_last_number(str, j))
		return (error_message(COLOR_RT), false);
	if (!check_range_int(color_f->r, 255, 255)
		|| !check_range_int(color_f->g, 255, 255)
		|| !check_range_int(color_f->b, 255, 255))
		return (error_message(COLOR_RANGE), false);
	return (true);
}

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
	if (!skip_and_set(rt->rt[i], &j, &(rt->light->position),
			(bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(rt->rt[i], &j, &(rt->light->brightness),
			(bool (*)(void *, char *, size_t *))set_brightness))
		return (false);
	if (!skip_and_set(rt->rt[i], &j, &(rt->light->color),
			(bool (*)(void *, char *, size_t *))set_color_light))
		return (false);
	return (true);
}
