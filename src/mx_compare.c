#include "../inc/uls.h"

bool mx_compare(void *a, void *b) {
    if (mx_strcmp((char *)a, (char *)b) > 0)
        return 1;
    else
        return 0;
}
