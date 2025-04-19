/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:37:50 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 18:37:55 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_object(void *object)
{
	t_object	*obj;

	obj = (t_object *)object;
	if (obj->object)
	{
		free(obj->object);
		obj->object = NULL;
	}
	free(obj);
}
