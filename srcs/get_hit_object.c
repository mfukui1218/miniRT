/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:57:34 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/26 15:46:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	hit_object(t_ray ray, t_object *object, double *t);

t_object	*get_hit_object(t_rt *rt, t_ray *ray)
{
	t_list		*lst;
	double		closest_t;
	double		current_t;
	bool		is_init;
	t_object	*closest_obj;

	lst = rt->object;
	closest_obj = NULL;
	is_init = false;
	while (lst)
	{
		if (hit_object(*ray, (t_object *)lst->content, &current_t))
		{
			if (is_init == false || current_t < closest_t)
			{
				closest_t = current_t;
				closest_obj = (t_object *)lst->content;
				is_init = true;
			}
		}
		lst = lst->next;
	}
	return (closest_obj);
}

static bool	hit_object(t_ray ray, t_object *object, double *t)
{
	if (object->type == SPHERE)
		return (hit_sphere(ray, (t_sphere *)object->object, t));
	else if (object->type == PLANE)
		return (hit_plane(ray, (t_plane *)object->object, t));
	else if (object->type == CYLINDER)
		return (hit_cylinder(ray, (t_cylinder *)object->object, t));
	else
		return (false);
}
