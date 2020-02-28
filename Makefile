NAME = uls

FILES = main \
		mx_flag_l \
		mx_l_out_st_blocks \
		mx_l_out_st_mode \
		mx_l_out_st_nlink \
		mx_l_out_st_uid \
		mx_l_out_st_gid \
		mx_l_out_st_size \
		mx_l_out_st_dev \
		mx_l_out_st_mtime \
		mx_read_uls \
		mx_print_uls \
		mx_longest_name \
		mx_lines_count \
		mx_is_ascii \
		mx_max_len_int \
		mx_max_len_char \
		mx_len_int \
		mx_compare \
		mx_sort_for_columns \
		mx_strjoin_for_path \
		mx_flags_trig \
		mx_vivod_total \
		mx_read_directory \
		mx_dir_name_print \
		mx_flag_one \
		mx_flag_d \
		mx_list_swap \
		mx_sort_by_time \
		mx_sort_by_size \
		mx_flags_obnulyator \
		mx_flag_p \
		mx_list_reverse \
		mx_change_argv \
		mx_r_bubble_sort \
		mx_err_print \

SRC_PREFFIX = $(addprefix src/, $(FILES))

HEADER = inc/uls.h

DEL_SRC = $(addsuffix .c, $(FILES))

SRC = $(addsuffix .c, $(SRC_PREFFIX))

SRC_COMPILE = $(addsuffix .c, $(SRC_PREFFIX))

OBJ = $(addsuffix .o, $(FILES))

CFLAGS = -std=c11 -Werror -Wall -Wextra -Wpedantic

LIB_A = libmx/libmx.a

all: install

install: uls

uls : $(SRC) $(INC)
	@make -C libmx install
	@clang $(CFLAGS) -c $(SRC_COMPILE)
	@clang $(CFLAGS) $(OBJ) $(LIB_A) -o $(NAME)
	@mkdir -p obj
	@cp $(OBJ) obj/
	@rm -rf $(OBJ)

uninstall: clean
	@make -C libmx uninstall
	@rm -rf $(NAME)

clean:
	@make -C libmx clean
	@rm -rf obj

reinstall: uninstall install
