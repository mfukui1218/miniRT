/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_color_radiance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:09:59 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/25 03:19:40 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	mul_color_radiance(t_color color, double radiance)
{
	t_color	ret_color;

	ret_color.r = (int)(color.r * radiance);
	ret_color.g = (int)(color.g * radiance);
	ret_color.b = (int)(color.b * radiance);
	return (ret_color);
}
