#include "../inc/uls.h"

int mx_len_int(unsigned long n) {
    int count = 0;
    int temp = n;

    if (n != 0) {
        while (temp > 0){
            temp = temp/10;
            count++;
        }
    }
    else
        count = 1;
    return count;
}
