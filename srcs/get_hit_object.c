/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:57:34 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/22 20:54:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_object_list(t_rt *rt, t_ray ray,
	t_object **hit_obj, double *closest_t);

t_object	*get_hit_object(const t_rt *rt, const t_ray *ray)
{
	(void)rt;
	(void)ray;
	t_object	*obj;
	double		closest_t;

	obj = NULL;
	hit_object_list((t_rt *)rt, (t_ray)*ray, &obj, &closest_t);
	return (obj);
}
