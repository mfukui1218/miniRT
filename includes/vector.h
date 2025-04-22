#ifndef VECTOR_H
#define VECTOR_H

typedef struct s_vector
{
	double x;
	double y;
	double z;
}	t_vector;

t_vector vec_add(t_vector a, t_vector b);
t_vector vec_sub(t_vector a, t_vector b);
t_vector vec_mul(t_vector a, t_vector b);
t_vector vec_normalize(t_vector v);
t_vector vec_cross(t_vector a, t_vector b);


#endif
