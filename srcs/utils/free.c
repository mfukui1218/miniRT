#include "miniRT.h"

void free_miniRT(t_miniRT *miniRT)
{
    if (!miniRT)
        return;
    if (miniRT->win)
        mlx_destroy_window(miniRT->mlx, miniRT->win);
    if (miniRT->mlx)
        mlx_destroy_display(miniRT->mlx);
    if (miniRT->camera)
        free_camera(miniRT->camera);
    if (miniRT->light)
        free_light(miniRT->light);
    if (miniRT->object)
        free_object(miniRT->object);
    if (miniRT->scene)
        free_scene(miniRT->scene);
    if (miniRT->vector)
        free_vector(miniRT->vector);
    if (miniRT->color)
        free_color(miniRT->color);
    if (miniRT->ray)
        free_ray(miniRT->ray);
    free(miniRT);
}

void free_camera(t_camera *camera)
{
    free(camera);
}

void free_light(t_light *light)
{
    free(light);
}

void free_object(t_object *object)
{
    free(object);
}

void free_scene(t_scene *scene)
{
    if (scene->camera)
        free_camera(scene->camera);
    if (scene->lights)
        free_light(scene->lights);
    if (scene->objects)
        free_object(scene->objects);
    free(scene);
}

void free_vector(t_vector *vector)
{
    free(vector);
}

void free_color(t_color *color)
{
    free(color);
}