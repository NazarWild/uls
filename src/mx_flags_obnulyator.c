#include "../inc/uls.h"

s_flags *mx_flags_obnulyator(void) {
    s_flags *flags = (s_flags *)malloc(sizeof(s_flags));

    flags->l = 0;
    flags->a = 0;
    flags->A = 0;
    flags->o = 0;
    flags->one = 0;
    flags->g = 0;
    flags->t = 0;
    flags->u = 0;
    flags->U = 0;
    flags->c = 0;
    flags->T = 0;
    flags->r = 0;
    flags->p = 0;
    flags->f = 0;
    flags->S = 0;
    flags->X = 0;
    flags->dir_print = 0;
    return flags;
}

