/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:18:14 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:31:53 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_cylinder(t_cylinder *cylinder)
{
	cylinder->position = (t_vector){0, 0, 0};
	cylinder->orientation = (t_vector){0, 0, 1};
	cylinder->radius = 0;
	cylinder->height = 0;
}
