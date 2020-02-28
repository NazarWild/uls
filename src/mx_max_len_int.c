#include "../inc/uls.h"

static int part(int trig, struct stat buf) {
    int n = 0;

    if (trig == 1)
        n = mx_len_int(buf.st_nlink);
    if (trig == 2)
        n = mx_len_int(buf.st_size);
    if (trig == 3)
        n = mx_len_int(MX_MAJOR(buf.st_rdev));
    if (trig == 4)
        n = mx_len_int(MX_MINOR(buf.st_rdev));
    if (trig == 5)
        n = mx_len_int(buf.st_blocks);
    return n;
}

int mx_max_len_int(t_list *names, int trig, char *argv, s_flags *flags) {
    int len = 0;
    t_list *p = names;
    struct stat buf;
    int n = 0;
    char *full_path = NULL;

    while (p) {
        full_path = mx_strjoin_for_path(argv, p->data, flags);
        lstat(full_path, &buf);
        n = part(trig, buf);
        if (n > len)
            len = n;
        p = p->next;
        if (flags->Y)
            mx_strdel(&full_path);
    }
    return len;
}
