#include "../inc/uls.h"

static char *part_1(int len, char *date) {
    int i;
    int j = 0;
    char *new = (char *) malloc(sizeof(char *) * len);

    for (i = 4; i < len - 14; i++) {
        new[j] = date[i];
        j++;
    }
    new[j] = ' ';
    j++;
    for (i = len - 5; i < len; i++) {
        new[j] = date[i];
        j++;
    }
    return new;
}

static char *part_2(int len, char *date) {
    int i;
    int j = 0;
    char *new = (char *) malloc(sizeof(char *) * len);

    for (i = 4; i < len - 9; i++) {
        new[j] = date[i];
        j++;
    }
    new[len - 9] = ' ';
    for (i = len - 8; i < len; i++) {
        new[j] = '\0';
        j++;
    }
    return new;
}

static char *l_change_date(char *date, long n, s_flags *fl) {
    int len = mx_strlen(date);
    long dtime = time(NULL);
    char *new = NULL;
    int diff = (dtime - n); 

    date[len - 1] = '\0';
    if (!fl->T) {
        if (diff > 183 * 86400) {
            new = part_1(len, date);
        }
        else {
            new = part_2(len, date);
        }
    }
    else
        new = mx_strdup(&date[4]);
    return new;
}

static char *for_time(long n, s_flags *fl) {
    char *date = NULL;

    date = ctime(&n);
    date = l_change_date(date, n, fl);
    return date;
}

void mx_l_out_st_mtime(long *amcb, s_flags *fl) {
    char *date = NULL;

    if (!fl->c && !fl->U && !fl->u) {
        date = for_time(amcb[1], fl);
    }
    if (fl->u) {
        date = for_time(amcb[0], fl);
    }
    if (fl->U) {
        date = for_time(amcb[3], fl);
    }
    if (fl->c) {
        date = for_time(amcb[2], fl);
    }
    mx_printstr(date);
    mx_printchar(' ');
    if (malloc_size(date))
        free(date);
}
