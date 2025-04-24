/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:57:34 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/25 02:37:31 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	*get_hit_object(t_rt *rt, t_ray *ray)
{
	t_list		*lst;
	t_object	*obj;
	double		closest_t;
	double		current_t;
	t_object	*closest_obj;

	lst = rt->object;
	closest_obj = NULL;
	closest_t = DBL_MAX;
	while (lst)
	{
		obj = (t_object *)lst->content;
		current_t = DBL_MAX;
		if (obj->type == SPHERE && hit_sphere(*ray, (t_sphere *)obj->object, &current_t))
		{
			if (current_t < closest_t)
			{
				closest_t = current_t;
				closest_obj = obj;
			}
		}
		else if (obj->type == PLANE && hit_plane(*ray, (t_plane *)obj->object, &current_t))
		{
			if (current_t < closest_t)
			{
				closest_t = current_t;
				closest_obj = obj;
			}
		}
		else if (obj->type == CYLINDER && hit_cylinder(*ray, (t_cylinder *)obj->object, &current_t))
		{
			if (current_t < closest_t)
			{
				closest_t = current_t;
				closest_obj = obj;
			}
		}
		lst = lst->next;
	}
	return (closest_obj);
}
