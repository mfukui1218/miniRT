#include "miniRT.h"

int main()
{
    t_miniRT *miniRT;

    miniRT = malloc(sizeof(t_miniRT));
    if (!miniRT)
        return (EXIT_FAILURE);
    init_miniRT(miniRT);
    mlx_destroy_image(mlx.mlx_ptr, mlx.img);
    mlx_destroy_window(mlx.mlx_ptr, mlx.win);
    return 0;
}

