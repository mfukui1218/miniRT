#include "miniRT.h"

bool	parse_ambient(t_rt *rt)
{
	size_t	i;
	size_t	j;

	rt->ambient = malloc(sizeof(t_color));
	if (!rt->ambient)
		return (error_message(ALLOCATE), false);
	init_ambient(rt->ambient);
	i = find_line_str(rt->rt, "A");
	j = skip_space(rt->rt[i]) + 1;
	if (!skip_and_set(rt->rt[i], &j, &(rt->ambient->brightness), (bool (*)(void *, char *, size_t *))set_brightness))
		return (false);
	if (!skip_and_set(rt->rt[i], &j, &(rt->ambient->color), (bool (*)(void *, char *, size_t *))set_color))
		return (false);
	return (true);  
}