/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_brightness.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:12:36 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 17:13:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_brightness(void *brightness, char *str, size_t *j)
{
	double	*brightness_f;

	brightness_f = (double *)brightness;
	*brightness_f = ft_atod_index_dev(str, j, true);
	if (*brightness_f < 0.0f || *brightness_f > 1.0f)
		return (error_message(BRIGHTNESS_RANGE), false);
	return (true);
}
