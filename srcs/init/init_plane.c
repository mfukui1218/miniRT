/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:18:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/21 20:43:39 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_plane(t_plane *plane)
{
	plane->position = (t_vector){0, 0, 0};
	plane->orientation = (t_vector){0, 0, 1};
	plane->color = (t_color){0, 0, 0};
}
