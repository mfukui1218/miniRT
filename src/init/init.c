#include "miniRT.h"

void init_all(t_miniRT *miniRT)
{
    mlx_init(miniRT->mlx);
    mlx_new_window(miniRT->mlx, miniRT->scene->width, miniRT->scene->height);
    init_mlx_image(miniRT->mlx, miniRT->scene->width, miniRT->scene->height);
    init_scene(miniRT->scene);
    init_camera(miniRT->camera);
    init_light(miniRT->light);
    init_object(miniRT->object);
    init_vector(miniRT->vector);
    init_color(miniRT->color);
}

void init_scene(t_scene *scene)
{
    scene->camera = NULL;
    scene->lights = NULL;
    scene->objects = NULL;
    scene->ambient = NULL;
    scene->width = 0;
    scene->height = 0;
    scene->background_color = (t_color){0, 0, 0};
    scene->light_intensity = 0.0;
}

void init_camera(t_camera *camera)
{
    camera->position = (t_vector){0, 0, 0};
    camera->orientation = (t_vector){0, 0, -1};
    camera->fov = 0;
    camera->aspect_ratio = 0;
}

void init_light(t_light *light)
{
    light->position = (t_vector){0, 0, 0};
    light->intensity = 0;
    light->color = (t_color){255, 255, 255};
}

void init_object(t_object *object)
{
    object->type = 0;
    object->position = (t_vector){0, 0, 0};
    object->orientation = (t_vector){0, 0, 0};
    object->color = (t_color){255, 255, 255};
    object->radius = 0;
    object->height = 0;
    object->next = NULL;
}

void init_vector(t_vector *vector)
{
    vector->x = 0;
    vector->y = 0;
    vector->z = 0;
}

void init_color(t_color *color)
{
    color->r = 0;
    color->g = 0;
    color->b = 0;
}

void init_mlx_image(t_mlx *mlx, int width, int height)
{
    mlx->width = width;
    mlx->height = height;
    mlx->img = mlx_new_image(mlx->mlx_ptr, width, height);
    if (!mlx->img)
        exit(EXIT_FAILURE);
    mlx->img_data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
    if (!mlx->img_data)
        exit(EXIT_FAILURE);
}

void init_mlx_window(t_mlx *mlx, int width, int height)
{
    mlx->win = mlx_new_window(mlx->mlx_ptr, width, height, "miniRT");
    if (!mlx->win)
        exit(EXIT_FAILURE);
}
