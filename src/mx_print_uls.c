#include "../inc/uls.h"

static void tab_write(char *str, int longest_name) {
    int len = mx_strlen(str);
    int counter = 0;

    counter = longest_name / 8 - len / 8;
    while (counter) {
        mx_printchar('\t');
        counter--;
    }
}

static void printer(t_list *sorted_list, t_list **files, s_print *info) {
    t_list *buf = *files;
    int index = *(int *)sorted_list->data;

    while (index) {
        buf = buf->next;
        index--;
    }
    char *data = (char *)buf->data;
    mx_is_ascii(data, mx_strlen(data));
    mx_printstr((const char *)buf->data);
    if (sorted_list->next) {
        info->cast[1] = *(int *)sorted_list->next->data;
        if (info->cast[0] > info->cast[1] || info->files_count == info->lines)
            mx_printchar('\n');
        else
            tab_write((char *)buf->data, info->longest_name);
    }
}

void mx_print_uls(t_list **files, t_list *sorted_list) {
    s_print *info = (s_print *)malloc(sizeof(s_print));
    info->files_count = mx_list_size(*files);
    info->columns = (int *)malloc(sizeof(int));
    info->cast = (int *)malloc(sizeof(int) * 2);
    info->longest_name = mx_longest_name(*files);
    info->lines = mx_lines_count(
                  info->files_count, info->columns, info->longest_name);

    sorted_list = mx_sort_for_columns(info);
    while (sorted_list) {
        info->cast[0] = *(int *)sorted_list->data;
        printer(sorted_list, files, info);
        free(sorted_list->data);
        mx_pop_front(&sorted_list);
    }
    free(info->columns);
    free(info->cast);
    free(info);
    if (info->files_count)
        mx_printchar(10);
}
