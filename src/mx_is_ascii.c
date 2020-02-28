#include "../inc/uls.h"

void mx_is_ascii(char *str, int len) {
    if (isatty(1) != 0) {
        for (int i = 0; i < len; i++) {
            if (str[i] >= 0 && str[i] <= 31)
                str[i] = '?';
        }
    }
}
