#include "../inc/uls.h"

t_list *mx_list_reverse(t_list *files) {
    t_list *res = NULL;

    while (files) {
        mx_push_front(&res, files->data);
        mx_pop_front(&files);
    }
    return res;
}
