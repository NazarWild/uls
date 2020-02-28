#include "../inc/uls.h"

void mx_list_swap(t_list *lst) {
    void *buf = NULL;
    
    buf = lst->data;
    lst->data = lst->next->data;
    lst->next->data = buf;
}
