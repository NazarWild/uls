#include "../inc/uls.h"

static void sort_dirs(s_flags *flags, char **arr, int size) {
    if (!flags->r)
        mx_bubble_sort(arr, size);
    else
        mx_r_bubble_sort(arr, size);
}

static void p_dir_name_S_t(t_list *data, s_flags *flags, char *source) {
    if (flags->p)
        mx_flag_p(data, flags, source);
    if (flags->S)
        mx_sort_by_size(data, source, flags);
    else if (flags->t)
        mx_sort_by_time(flags, data, source, flags);
}

static void work_with_flags(s_flags *flags, t_list *data,
                            char *source, t_list *sorted_list) {
    p_dir_name_S_t(data, flags, source);
    if (flags->r)
        data = mx_list_reverse(data);
    if (flags->one)
        mx_flag_one(data);
    else if (flags->l)
        mx_flag_l(data, source, flags);
    else
        mx_print_uls(&data, sorted_list);
    while (data) {
        free(data->data);
        mx_pop_front(&data);
    }
}

static void list_creator(s_flags *flags, char *dirs, char **files, int i) {
    t_list *data = NULL;
    t_list *sorted_list = NULL;

    if (dirs) {
        if (flags->dir_print)
            mx_dir_name_print(i, dirs);
        mx_read_directory(dirs, &data, flags);
        mx_sort_list(data, &mx_compare);
        work_with_flags(flags, data, dirs, sorted_list);
    }
    else {
        flags->Y = 1;
        for (int i = 0; files[i]; i++)
            mx_push_front(&data, files[i]);
        mx_sort_list(data, &mx_compare);
        work_with_flags(flags, data, dirs, sorted_list);
    }
}

void mx_read_uls(char **files, char **dirs, s_flags *flags) {
    int size_files = mx_arrlen(files);
    int size_dirs = mx_arrlen(dirs);

    if (files && *files) {
        sort_dirs(flags, files, size_files);
        list_creator(flags, NULL, files, 0);
        if (size_dirs > 0)
            mx_printchar('\n');
    }
    if (dirs && *dirs) {
        flags->X = 1;
        if (dirs[1] || (dirs[0] && size_files > 0))
            flags->dir_print = 1;
        sort_dirs(flags, dirs, size_dirs);
        for (int i = 0; dirs[i]; i++)
            list_creator(flags, dirs[i], NULL, i);
    }
    else if (size_dirs == 0 && size_files == 0 && !flags->err)
        list_creator(flags, ".", NULL, 0);
}
