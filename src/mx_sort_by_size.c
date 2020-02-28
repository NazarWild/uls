#include "../inc/uls.h"

static void part_2(char *full1, char *full2) {
    if (malloc_size(full1))
        free(full1);
    if (malloc_size(full2))
        free(full2);
}

void mx_sort_by_size(t_list *files, char *argv, s_flags *flags) {
    struct stat buf1;
    struct stat buf2;
    char *full_path1 = NULL;
    char *full_path2 = NULL;
    t_list *p = files;

    for (int i = mx_list_size(files); i >= 0; i--) {
        while (p->next) {
            full_path1 = mx_strjoin_for_path(argv, p->data, flags);
            full_path2 = mx_strjoin_for_path(argv, p->next->data, flags);
            lstat(full_path1, &buf1);
            lstat(full_path2, &buf2);
            if (buf1.st_size < buf2.st_size)
                mx_list_swap(p);
            if (flags->Y)
               part_2(full_path1, full_path2);
            p = p->next;
        }
        p = files;
    }
}
