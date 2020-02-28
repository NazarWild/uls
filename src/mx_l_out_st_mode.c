#include "../inc/uls.h"

static int mx_for_plus_and_dog(char *prava, char *str) {
    acl_t acl = NULL;
    ssize_t attr = 0;
    int len = 2;

    attr = listxattr(str, NULL, 0, XATTR_NOFOLLOW);
    acl = acl_get_file(str, ACL_TYPE_EXTENDED);
    if (attr > 0) {
        prava[10] = '@';
        acl_free(acl);
        len--;
    }
    else if (acl != NULL) {
        prava[10] = '+';
        acl_free(acl);
        len--;
    }
    return len;
}

static void part_1(unsigned long n, char *prava) {
    prava[1] = (n & MX_IRUSR) == MX_IRUSR ? 'r' : '-';
    prava[2] = (n & MX_IWUSR) == MX_IWUSR ? 'w' : '-';
    prava[3] = (n & MX_IXUSR) == MX_IXUSR ? 'x' : '-';
    prava[4] = (n & MX_IRGRP) == MX_IRGRP ? 'r' : '-';
    prava[5] = (n & MX_IWGRP) == MX_IWGRP ? 'w' : '-';
    prava[6] = (n & MX_IXGRP) == MX_IXGRP ? 'x' : '-';
    prava[7] = (n & MX_IROTH) == MX_IROTH ? 'r' : '-';
    prava[8] = (n & MX_IWOTH) == MX_IWOTH ? 'w' : '-';
    prava[9] = (n & MX_IXOTH) == MX_IXOTH ? 'x' : '-';
}

static void part_2(unsigned long n, char *prava) {
    if ((n & MX_IFMT) == MX_IFREG)
        prava[0] = '-';
    else if ((n & MX_IFMT) == MX_IFDIR)
        prava[0] = 'd';
    else if ((n & MX_IFMT) == MX_IFBLK)
        prava[0] = 'b';
    else if ((n & MX_IFMT) == MX_IFCHR)
        prava[0] = 'c';
    else if ((n & MX_IFMT) == MX_IFIFO)
        prava[0] = 'p';
    else if ((n & MX_IFMT) == MX_IFLNK)
        prava[0] = 'l';
    else if ((n & MX_IFMT) == MX_IFSOCK)
        prava[0] = 's';
    else
        prava[0] = '-';
}

void mx_l_out_st_mode(unsigned long n, char *name) {
    char *prava = mx_strnew(12);
    int len = 0;

    part_1(n, prava);
    part_2(n, prava);
    if ((n & MX_ISUID) == MX_ISUID)
        prava[3] = 's';
    if ((n & MX_ISGID) == MX_ISGID)
        prava[6] = 's';
    if ((n & MX_ISVTX) == MX_ISVTX)
        prava[9] = 't';
    len = mx_for_plus_and_dog(prava, name);
    mx_printstr(prava);
    while (len > 0) {
        mx_printchar(' ');
        len--;
    }
    mx_strdel(&prava);
}
