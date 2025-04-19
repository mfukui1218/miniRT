/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:16:48 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 17:31:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_color(const t_color *color)
{
	if (color == NULL)
		return ;
	printf(FMT_24COLOR "■ " CLC "(%d, %d, %d)\n",
		color->r, color->g, color->b,
		color->r, color->g, color->b);
}
