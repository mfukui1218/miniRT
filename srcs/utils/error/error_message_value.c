/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:25:22 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:25:27 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	error_message_value(int err)
{
	if (error_coordinate(err))
		return (true);
	if (error_brightness(err))
		return (true);
	if (error_color(err))
		return (true);
	if (error_fov(err))
		return (true);
	if (error_vector(err))
		return (true);
	if (error_radius(err))
		return (true);
	if (error_cylinder(err))
		return (true);
	if (error_ambient(err))
		return (true);
	return (false);
}
