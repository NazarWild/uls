#include "../inc/uls.h"

static bool cycle_body_stat(s_index *index, char **argv,
                            char **dirs, char **files) {
    struct stat lt;
    bool res = 0;

    if (lstat(argv[index->index], &lt) != -1) {
        if ((lt.st_mode & MX_IFMT) == MX_IFDIR)
            dirs[index->i++] = mx_strdup(argv[index->index]);
        else
            files[index->j++] = mx_strdup(argv[index->index]);
        res = 1;
    }
    return res;
}

static bool cycle_body_lstat(s_index *index, char **argv,
                             char **dirs, char **files) {
    struct stat lt;
    bool res = 0;

    if (stat(argv[index->index], &lt) != -1) {
        if ((lt.st_mode & MX_IFMT) == MX_IFDIR)
            dirs[index->i++] = mx_strdup(argv[index->index]);
        else
            files[index->j++] = mx_strdup(argv[index->index]);
        res = 1;
    }
    return res;
}

static char **ways_creator(char **argv, char **files,
                           s_index *index, s_flags *flags) {
    char **dirs = (char **)malloc(sizeof(char *) * index->argc - index->index + 1);

    for (; index->index < index->argc; index->index++) {
        if (flags->l) {
            if (cycle_body_lstat(index, argv, dirs, files));
            else
                mx_err_print(flags, argv, index->index);
        }
        else {
            if (cycle_body_stat(index, argv, dirs, files));
            else
                mx_err_print(flags, argv, index->index);
        }
    }
    files[index->j] = NULL;
    dirs[index->i] = NULL;
    return dirs;
}

static void parser(char **argv, s_index *index,
                   s_flags *flags, char **files) {
    char **dirs = NULL;

    for (; argv[index->index] && argv[index->index][0] == '-'
           && argv[index->index][1]; index->index++) {
        if (argv[index->index][1] == '-' && !argv[index->index][2]) {
            index->index++;
            break;
        }
        for (int q = 1; argv[index->index][q]; q++)
            mx_flags_trig(argv[index->index][q], flags);
    }
    files = (char **)malloc(sizeof(char *) * index->argc - index->index + 1);
    dirs = ways_creator(argv, files, index, flags);
    mx_read_uls(files, dirs, flags);
    mx_del_strarr(&dirs);
    free(files);
}

int main(int argc, char **argv) {
    s_flags *flags = mx_flags_obnulyator();
    s_index *index = (s_index *)malloc(sizeof(s_index));
    char **files = NULL;

    index->argc = argc;
    index->index = 1;
    index->i = 0;
    index->j = 0;
    flags->err = 0;
    flags->Y = 0;
    if (argc > 1)
        parser(argv, index, flags, files);
    else
        mx_read_uls(NULL,NULL, flags);
    return flags->err;
}