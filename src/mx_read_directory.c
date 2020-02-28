#include "../inc/uls.h"

static void err_print(char *str) {
    mx_printerr("uls: ");
    perror(str);
}

static bool trig_a(char *d_name, s_flags *flags) {
    if (flags->a
        || (flags->A && (mx_strcmp(d_name, ".") && mx_strcmp(d_name, "..")))
        || (!flags->a && !flags->A && (mx_strcmp(d_name, ".")
        && mx_strcmp(d_name, "..") && d_name[0] != '.')))
        return 1;
    else
        return 0;
}

static void part_1(t_list **files, s_flags *flags, DIR *directory) {
    struct dirent *lupa = NULL;
    char *buf = NULL;

    while ((lupa = readdir(directory)) != NULL) {
        if (trig_a(lupa->d_name, flags)) {
            buf = mx_strdup(lupa->d_name);
            mx_push_front(files, buf);
        }
    }
    closedir(directory);
    flags->X = 1;
}

int mx_read_directory(char *source, t_list **files, s_flags *flags) {
    DIR *directory = opendir(source);
    char *buf = NULL;
    struct stat lt;

    if (directory) {
        stat(source, &lt);
        part_1(files, flags, directory);
    }
    else {
        flags->err = 1;
        buf = mx_change_argv(source, mx_strlen(source));
        err_print(buf);
    }
    return flags->err;
}
