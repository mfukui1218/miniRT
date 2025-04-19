/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_with_indent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:59:24 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 00:59:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_with_indent(t_print_func f, const void *arg)
{
	rt_print_indent(1);
	f(arg);
	rt_print_indent(-1);
}
