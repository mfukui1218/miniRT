/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:19:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 17:13:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_coordinate(void *vec, char *str, size_t *j)
{
	t_vector	*vec_f;

	vec_f = (t_vector *)vec;
	vec_f->x = ft_atod_index_dev(str, j, false);
	if (!check_number_with_comma(str, j))
		return (error_message(COORD_RT), false);
	vec_f->y = ft_atod_index_dev(str, j, false);
	if (!check_number_with_comma(str, j))
		return (error_message(COORD_RT), false);
	vec_f->z = ft_atod_index_dev(str, j, false);
	if (!check_last_number(str, j))
		return (error_message(COORD_RT), false);
	if (!check_range_double(vec_f->x, -1000.0f, 1000.0f)
		|| !check_range_double(vec_f->y, -1000.0f, 1000.0f)
		|| !check_range_double(vec_f->z, -1000.0f, 1000.0f))
		return (error_message(COORD_RANGE), false);
	return (true);
}
