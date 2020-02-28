#include "../inc/uls.h"

static bool check_flag3(char f, s_flags *trig) {
	if (f == 'g') {
        trig->g = 1;
        trig->one = 0;
        trig->l = 1;
    }
	else if (f == 'T')
		trig->T = 1;
	else if (f == 'f')
		trig->f = 1;
	else if (f == 'p')
		trig->p = 1;
	else if (f == 'r')
		trig->r = 1;
	else if (f == 't')
		trig->t = 1;
	else
		return false;
	return true;
}

static bool check_flag2(char f, s_flags *trig) {
	if (f == 'U'){
		trig->U = 1;
		trig->c = 0;
		trig->u = 0;
	}
    else if (f == 'a')
        trig->a = 1;
	else if (f == 'c'){
		trig->U = 0;
		trig->c = 1;
		trig->u = 0;
	}
	else if (f == 'u'){
		trig->U = 0;
		trig->c = 0;
		trig->u = 1;
	}
	else
		return false;
	return true;
}

static bool check_flag1(char f, s_flags *trig) {
	if (f == 'A')
		trig->A = 1;
	else if (f == 'l') {
        trig->l = 1;
        trig->one = 0;
    }
	else if (f == 'o') {
        trig->o = 1;
        trig->one = 0;
        trig->l = 1;
    }
	else if (f == '1') {
        trig->one = 1;
        trig->l = 0;
    }
	else if (f == 'S')
		trig->S = 1;
	else
		return false;
	return true;
}

void mx_flags_trig(char f, s_flags *trig) {
	if (!check_flag1(f, trig) && !check_flag2(f, trig) 
		&& !check_flag3(f, trig)) {
	    mx_printerr("uls: illegal option -- ");
	    write(2, &f, 1);
	    write(2, "\n", 1);
        mx_printerr("usage: uls [-ATSUalo1gtucpr] [file ...]\n");
        exit(1);
    }
}
