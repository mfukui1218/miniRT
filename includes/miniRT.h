#ifndef MINIRT_H
#define MINIRT_H

#include "../minilibx-linux/mlx.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>

typedef struct s_camera t_camera;
typedef struct s_light t_light;
typedef struct s_object t_object;
typedef struct s_scene t_scene;
typedef struct s_ray t_ray;

typedef struct s_color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} t_color;

typedef struct miniRT
{
    void *mlx;
    t_camera *camera;
    t_light *light;
    t_object *object;
    t_scene *scene;
    t_vector *vector;
    t_color *color;
    t_ray *ray;
} t_miniRT;

typedef struct s_camera
{
    t_vector position;
    t_vector orientation;
    double fov;
} t_camera;

typedef struct s_light
{
    t_vector position;
    double brightness;
    t_color color;
} t_light;

typedef struct s_object
{
    int type;
    t_vector position;
    t_vector orientation;
    t_color color;
    double radius;
    double height;
} t_object;

typedef struct s_scene
{
    t_camera *camera;
    t_light *lights;
    t_object *objects;
    t_color ambient;
    int width;
    int height;
    t_color background_color;
    double light_intensity;
} t_scene;

typedef struct s_ray
{
    t_vector origin;
    t_vector direction;
} t_ray;


void init_miniRT(t_miniRT *miniRT);
void init_camera(t_camera *camera);
void init_light(t_light *light);
void init_object(t_object *object);
void init_scene(t_scene *scene);
void init_vector(t_vector *vector);
void init_color(t_color *color);
void init_ray(t_ray *ray);


#endif