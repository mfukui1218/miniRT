#include "miniRT.h"

void init_miniRT(t_miniRT *miniRT)
{
    mlx_init(miniRT->mlx);
    miniRT->win = NULL;
    init_camera(miniRT->camera);
    init_light(miniRT->light);
    init_object(miniRT->object);
    init_scene(miniRT->scene);
    init_vector(miniRT->vector);
    init_color(miniRT->color);
    init_ray(miniRT->ray);
}

void init_camera(t_camera *camera)
{
    camera->position = (t_vector){0, 0, 0};
    camera->orientation = (t_vector){0, 0, -1};
    camera->fov = 0;
}

void init_light(t_light *light)
{
    light->position = (t_vector){0, 0, 0};
    light->brightness = 0;
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
}

void init_scene(t_scene *scene)
{
    scene->camera = NULL;
    scene->lights = NULL;
    scene->objects = NULL;
    scene->ambient = (t_color){0, 0, 0};
    scene->width = 0;
    scene->height = 0;
    scene->background_color = (t_color){0, 0, 0};
    scene->light_intensity = 0.0;
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

void init_ray(t_ray *ray)
{
    ray->origin = (t_vector){0, 0, 0};
    ray->direction = (t_vector){0, 0, 0};
}