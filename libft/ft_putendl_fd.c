/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putendl_fd.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mfukui <mfukui@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/22 15:42:24 by mfukui			#+#	#+#			 */
/*   Updated: 2023/09/27 00:41:37 by mfukui		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}
