#include "miniRT.h"

int main()
{
    t_miniRT *miniRT;

    miniRT = malloc(sizeof(t_miniRT *));
    if (!miniRT)
        return (EXIT_FAILURE);
    init_miniRT(miniRT);
    miniRT->win = mlx_new_window(miniRT->mlx, 800, 600, "miniRT");
    if (!miniRT->win)
        return (free(miniRT), EXIT_FAILURE);
    miniRT->camera = malloc(sizeof(t_camera *));
    if (!miniRT->camera)
        return (free(miniRT), EXIT_FAILURE);
    return 0;
}

