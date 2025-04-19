/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:14:28 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 17:31:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_vector(const t_vector *vector)
{
	if (vector == NULL)
		return ;
	printf("(%f, %f, %f)", vector->x, vector->y, vector->z);
}
