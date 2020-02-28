#ifndef ULS_H
#define ULS_H

#include "../libmx/inc/libmx.h"
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <malloc/malloc.h>

#define MX_IFMT   0170000  /* type of file mask */
#define MX_IFIFO  0010000  /* named pipe (fifo) */
#define MX_IFCHR  0020000  /* character special */
#define MX_IFDIR  0040000  /* directory */
#define MX_IFBLK  0060000  /* block special */
#define MX_IFREG  0100000  /* regular */
#define MX_IFLNK  0120000  /* symbolic link */
#define MX_IFSOCK 0140000  /* socket */
#define MX_IFWHT  0160000  /* whiteout */
#define MX_ISUID  0004000  /* set user id on execution */
#define MX_ISGID  0002000  /* set group id on execution */
#define MX_ISVTX  0001000  /* save swapped text even after use */
#define MX_IRWXU  0000700  /* RWX mask for owner */
#define MX_IRUSR  0000400        /* R ead permission, owner */
#define MX_IWUSR  0000200        /* W rite permission, owner */
#define MX_IXUSR  0000100        /* X execute/search permission, owner */
#define MX_IRWXG  0000070  /* RWX mask for group */
#define MX_IRGRP  0000040        /* R ead permission, group */
#define MX_IWGRP  0000020        /* W rite permission, group */
#define MX_IXGRP  0000010        /* X execute/search permission, group */
#define MX_IRWXO  0000007  /* RWX mask for other */
#define MX_IROTH  0000004        /* R ead permission, other */
#define MX_IWOTH  0000002        /* W rite permission, other */
#define MX_IXOTH  0000001        /* X execute/search permission, other */
#define MX_MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define MX_MINOR(x) ((int32_t)((x) & 0xffffff))

typedef struct t_main {
    int argc;
    int index;
    int i;
    int j;
} s_index;

typedef struct t_print_uls {
    int files_count;
    int *columns;
    int longest_name;
    int lines;
    int *cast;
} s_print;

typedef struct t_flags {
    bool l;//+
    bool a;//+
    bool A;//+
    bool o;//+
    bool one;//+
    bool g;//+
    bool t;//+
    bool u;//+
    bool U;//+
    bool c;//+
    bool T;//+
    bool p;//+
    bool S;//+
    bool r;//-
    bool f;//-
    bool X;//
    bool dir_print;//
    bool err;//
    bool Y;//
} s_flags;

t_list *mx_list_reverse(t_list *files);
t_list *mx_sort_for_columns(s_print *info);
bool mx_compare(void *a, void *b);
int mx_longest_name(t_list *list);
int mx_lines_count(int files_count, int *columns, int longest_name);
int mx_read_directory(char *source, t_list **files, s_flags *flags);
void mx_read_uls(char **files, char **dirs, s_flags *flags);
void mx_print_uls(t_list **files, t_list *sorted_list);
void mx_flag_l(t_list *names, char *argv, s_flags *flags);
void mx_l_out_st_blocks(unsigned long n, int otstup);
void mx_l_out_st_mode(unsigned long n, char *name);
void mx_l_out_st_nlink(unsigned long n, int otstup, s_flags *fl);
void mx_l_out_st_uid(unsigned int n, int otstup);
void mx_l_out_st_gid(unsigned long n, int otstup);
void mx_l_out_st_size(unsigned long n, int otstup);
void mx_l_out_st_dev(unsigned int n, int otstup1, int otstup2);
void mx_is_ascii(char *str, int len);
void mx_l_out_st_mtime(long *amcb, s_flags *fl);
int mx_max_len_int(t_list *names, int trig, char *argv, s_flags *flags);
int mx_max_len_char(t_list *src, int trig, char *argv, s_flags *flags);
char *mx_strjoin_for_path(char *argv, char *data, s_flags *flags);
char *mx_change_argv(char *temp, int len);
int mx_len_int(unsigned long n);
void mx_flags_trig(char f, s_flags *trig);
void mx_vivod_total(t_list *names, char *argv, s_flags *fl);
void mx_dir_name_print(int i, char *source);
void mx_flag_one(t_list *names);
void mx_err_print(s_flags *flags, char **argv, int index);
void mx_flag_d(char *source, t_list **files);
void mx_list_swap(t_list *lst);
void mx_sort_by_time(s_flags *fl, t_list *files, char *argv, s_flags *flags);
void mx_sort_by_size(t_list *files, char *argv, s_flags *flags);
s_flags *mx_flags_obnulyator(void);
void mx_flag_p(t_list *files, s_flags *fl, char *argv);
int mx_r_bubble_sort(char **arr, int size);

#endif
