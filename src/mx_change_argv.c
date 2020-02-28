#include "../inc/uls.h"

char *mx_change_argv(char *temp, int len) {
    int i = len - 1;
    int j = 0;
    char *res = NULL;

    while (temp[i] != '/')
        i--;
    i++;
    res = (char *)malloc(sizeof(char) * len - i);
    while (temp[i]) {
        res[j] = temp[i];
        i++;
        j++;
    }
    res[j] = '\0';
    return res;
}
