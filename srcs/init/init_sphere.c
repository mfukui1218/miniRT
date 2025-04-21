/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:18:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/21 20:43:17 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_sphere(t_sphere *sphere)
{
	sphere->position = (t_vector){0, 0, 0};
	sphere->radius = 0;
	sphere->color = (t_color){0, 0, 0};
}
