#include "../inc/uls.h"

int mx_longest_name(t_list *list) {
    t_list *buf = list;
    int max = 0;
    int i = 0;

    if (!buf)
        return -1;
    else {
        while (buf) {
            if (max < mx_strlen(buf->data))
                max = mx_strlen(buf->data);
            i++;
            buf = buf->next;
        }
    }
    max = max + (8 - max % 8);
    return max;
}
