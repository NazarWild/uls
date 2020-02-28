#include "../inc/uls.h"

static void part_1(struct stat buf1, struct stat buf2,
                   t_list *p, s_flags *fl) {
    if (fl->u) {
        if (buf1.st_atime < buf2.st_atime)
            mx_list_swap(p);
    }
    else if (fl->c) {
        if (buf1.st_ctime < buf2.st_ctime)
            mx_list_swap(p);
    }
    else if (fl->U) {
        if (buf1.st_birthtime < buf2.st_birthtime)
            mx_list_swap(p);
    }
    else {
        if (buf1.st_mtime < buf2.st_mtime)
            mx_list_swap(p);
    }
}

static void part_2(char *full1, char *full2) {
    if (malloc_size(full1))
        free(full1);
    if (malloc_size(full2))
        free(full2);
}

void mx_sort_by_time(s_flags *fl, t_list *files, char *argv, s_flags *flags) {
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
            part_1(buf1, buf2, p, fl);
            if (flags->Y)
                part_2(full_path1, full_path2);
            p = p->next;
        }
        p = files;
    }
}
