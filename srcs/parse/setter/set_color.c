/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:12:56 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 15:02:35 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_color(void *color, char *str, size_t *j)
{
	t_color	*color_f;

	color_f = (t_color *)color;
	color_f->r = ft_atoi(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	color_f->g = ft_atoi(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	color_f->b = ft_atoi(&str[*j]);
	if (!checklast_last_number(str, j))
		return (error_message(COLOR_RT), false);
	if (!check_range_int(color_f->r, 0, 255)
		|| !check_range_int(color_f->g, 0, 255)
		|| !check_range_int(color_f->b, 0, 255))
		return (error_message(COLOR_RANGE), false);
	return (true);
}
