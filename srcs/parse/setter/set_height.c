/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:14:46 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 17:13:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_height(void *height, char *str, size_t *j)
{
	double	*height_f;

	height_f = (double *)height;
	*height_f = ft_atod_index_dev(str, j, true);
	if (*height_f < 0.0f)
		return (error_message(CYLINDER_RANGE), false);
	return (true);
}
