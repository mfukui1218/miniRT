#include "miniRT.h"

int main()
{
    t_miniRT *miniRT;

    miniRT = malloc(sizeof(t_miniRT));
    if (!miniRT)
        return (EXIT_FAILURE);
    init_miniRT(miniRT);
    return 0;
}

