//
//  mjRotation.c
//  mjRotation
//
//  Created by Martin Jaroszewicz on 7/20/14.
//  Copyright (c) 2014 com.martinjaroszewicz. All rights reserved.
//

#include "m_pd.h"
#include <math.h>
#include <string.h>

static t_class *mjRotation_class;

typedef struct _mjRotation {
	t_object x_obj;
	//local variables
	t_float f_count;
	t_float f_x;
	t_float f_y;
	t_float f_z;
	t_float f_elipX;
    t_float f_elipZ;
    t_float f_input;
    t_float f_mult;
	t_outlet *l1_out, *l2_out, *l3_out;
} t_mjRotation;


void mjRotation_float(t_mjRotation *x, t_float f){
    t_float a1 = x->f_x;
    t_float a2 = x->f_y;
    t_float a3 = x->f_z;
    ;
    x->f_x = sin(f * x->f_mult)*x->f_elipX;
    x->f_y = 0;
    x->f_z = cos(f * x->f_mult)*x->f_elipZ;
    outlet_float(x->l1_out, a1);
    outlet_float(x->l2_out, a3);
    outlet_float(x->l3_out, a2); // This works for HOA Library
}

void *mjRotation_new(t_floatarg f){
    
    t_mjRotation *x = (t_mjRotation *)pd_new(mjRotation_class);
    x->f_mult = 3.14159 * 2;
    x->l1_out = outlet_new(&x->x_obj, &s_float);
    x->l2_out = outlet_new(&x->x_obj, &s_float);
    x->l3_out = outlet_new(&x->x_obj, &s_float);
    floatinlet_new(&x->x_obj, &x->f_elipX);
    floatinlet_new(&x->x_obj, &x->f_elipZ);
    
    return (void *)x;
}

void mjRotation_setup(void) {
    mjRotation_class = class_new(gensym("mjRotation"),
    (t_newmethod)mjRotation_new,
            0, sizeof(t_mjRotation),
            CLASS_DEFAULT,
            A_DEFFLOAT, 0);
    class_addfloat(mjRotation_class, mjRotation_float);
    
}
