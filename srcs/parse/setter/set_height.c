/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:14:46 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:15:01 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_height(void *height, char *str, size_t *j)
{
	float	*height_f;

	height_f = (float *)height;
	*height_f = ft_atof_index_dev(str, j, true);
	if (*height_f < 0.0f)
		return (error_message(CYLINDER_RANGE), false);
	return (true);
}
