/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul_color_radiance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:09:59 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 16:42:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	mul_color_radiance(t_color color, t_radiance radiance)
{
	t_color	ret_color;

	(void)color;
	(void)radiance;
	ft_memset(&ret_color, 0xff, sizeof(t_color));
	return (ret_color);
}
