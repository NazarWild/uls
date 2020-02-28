#include "../inc/uls.h"

void mx_flag_one(t_list *files) {
    t_list *p = files;

    while (p->next) {
        mx_printstr(p->data);
        mx_printchar(10);
        p = p->next;
    }
    mx_printstr(p->data);
    mx_printchar(10);
}
