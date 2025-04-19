/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:19:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:13:22 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_coordinate(void *vec, char *str, size_t *j)
{
	t_vector	*vec_f;

	vec_f = (t_vector *)vec;
	vec_f->x = ft_atof_index_dev(str, j, false);
	if (!check_number_with_comma(str, j))
		return (error_message(COORD_RT), false);
	vec_f->y = ft_atof_index_dev(str, j, false);
	if (!check_number_with_comma(str, j))
		return (error_message(COORD_RT), false);
	vec_f->z = ft_atof_index_dev(str, j, false);
	if (!check_last_number(str, j))
		return (error_message(COORD_RT), false);
	if (!check_range_float(vec_f->x, -1000.0f, 1000.0f)
		|| !check_range_float(vec_f->y, -1000.0f, 1000.0f)
		|| !check_range_float(vec_f->z, -1000.0f, 1000.0f))
		return (error_message(COORD_RANGE), false);
	return (true);
}
