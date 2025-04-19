/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_and_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:07:01 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 21:07:11 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	skip_and_set(char *line, size_t *j,
	void *dst, bool (*func)(void *, char *, size_t *))
{
	*j += skip_space(line + *j);
	if (!func(dst, line, j))
		return (false);
	return (true);
}
