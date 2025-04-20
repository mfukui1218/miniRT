/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_destroy_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:41:13 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 06:41:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_destroy_image(void *mlx, t_screen *img)
{
	if (img == NULL)
		return ;
	if (img->img != NULL)
	{
		mlx_destroy_image(mlx, img->img);
		img->img = NULL;
	}
	free(img);
}
