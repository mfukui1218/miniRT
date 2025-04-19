/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_brightness.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:12:36 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:12:39 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_brightness(void *brightness, char *str, size_t *j)
{
	float	*brightness_f;

	brightness_f = (float *)brightness;
	*brightness_f = ft_atof_index_dev(str, j, true);
	if (*brightness_f < 0.0f || *brightness_f > 1.0f)
		return (error_message(BRIGHTNESS_RANGE), false);
	return (true);
}
