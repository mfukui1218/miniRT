/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:03:38 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/27 16:00:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	calc_color(t_radiance radiance, t_color light, t_object *object)
{
	t_color	obj_color;
	t_color	ret_color;

	obj_color = get_object_color(object);
	ret_color.r = radiance * light.r * ((obj_color.r) / 255.0);
	ret_color.g = radiance * light.g * ((obj_color.g) / 255.0);
	ret_color.b = radiance * light.b * ((obj_color.b) / 255.0);
	return (ret_color);
}
