#include "../inc/uls.h"

static void counter_zero(int *counter, int columns, int *i) {
    if (*counter == columns) {
        *counter = 0;
        i[0]++;
    }
}

static int for_small_window(t_list **sorted_list, int files_count, int lines) {
    int *buffer = NULL;

    if (lines == files_count) {
        for (int i = 0; i < files_count; i++) {
            buffer = (int *)malloc(sizeof (int));
            buffer[0] = i;
            mx_push_back(sorted_list, buffer);
        }
        return 1;
    }
    else
        return 0;
}

t_list *mx_sort_for_columns(s_print *info) {
    t_list *sorted_list = NULL;
    int counter = 0;
    int i = 0;

    if (for_small_window(&sorted_list, info->files_count, info->lines))
        return sorted_list;
    for (int index = 0; index < info->files_count; index++, counter++) {
        counter_zero(&counter, *info->columns, &i);
        if (info->lines * counter + i < info->files_count) {
            int *buf = (int *)malloc(sizeof (int));
            buf[0] = info->lines * counter + i;
            mx_push_back(&sorted_list, buf);
        }
        else
            index--;
    }
    return sorted_list;
}
