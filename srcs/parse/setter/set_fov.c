/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:12:17 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 22:12:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	set_fov(void *fov, char *str, size_t *j)
{
	int		*fov_f;

	fov_f = (int *)fov;
	*fov_f = ft_atoi(&str[*j]);
	if (*fov_f < 0 || *fov_f > 180)
		return (error_message(FOV_RANGE), false);
	return (true);
}
