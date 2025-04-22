/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_normal_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:58:33 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 17:04:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	generate_normal_ray(
			const t_rt *rt, const t_ray *ray, const t_object *object)
{
	t_ray	normal_ray;

	(void)rt;
	(void)ray;
	(void)object;
	ft_memset(&normal_ray, 0, sizeof(t_ray));
	return (normal_ray);
}
