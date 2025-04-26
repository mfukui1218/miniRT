NAME        := miniRT

# ソースファイル（パス付き）
SRCS = \
	./gnl/get_next_line.c \
	./gnl/get_next_line_utils.c \
	./srcs/add_color.c \
	./srcs/calc_ambient_radiance.c \
	./srcs/event_handlers/rt_destroy_evenet_handler.c \
	./srcs/event_handlers/rt_expose_evenet_hander.c \
	./srcs/event_handlers/rt_key_event_handler.c \
	./srcs/get_color.c \
	./srcs/get_hit_object.c \
	./srcs/get_object_color.c \
	./srcs/init/init_ambient.c \
	./srcs/init/init_camera.c \
	./srcs/init/init_color.c \
	./srcs/init/init_cylinder.c \
	./srcs/init/init_light.c \
	./srcs/init/init_object.c \
	./srcs/init/init_plane.c \
	./srcs/init/init_rt.c \
	./srcs/init/init_sphere.c \
	./srcs/init/init_vector.c \
	./srcs/main/main.c \
	./srcs/math/solve_quadratic.c \
	./srcs/mlx/draw.c \
	./srcs/mlx/rt_destroy_image.c \
	./srcs/mlx/rt_draw_background.c \
	./srcs/mlx/rt_mlx_pixel_put.c \
	./srcs/mlx/rt_new_image.c \
	./srcs/mul_color_radiance.c \
	./srcs/parse/condition/check_last-number.c \
	./srcs/parse/condition/check_number_with_comma.c \
	./srcs/parse/condition/checklast_lastnumber.c \
	./srcs/parse/condition/is_valid_condition.c \
	./srcs/parse/element/parse_ambient.c \
	./srcs/parse/element/parse_camera.c \
	./srcs/parse/element/parse_light.c \
	./srcs/parse/object/parse_cylinder.c \
	./srcs/parse/object/parse_object.c \
	./srcs/parse/object/parse_plane.c \
	./srcs/parse/object/parse_sphere.c \
	./srcs/parse/parse_utils/check_range.c \
	./srcs/parse/parse_utils/check_range_double.c \
	./srcs/parse/parse_utils/find_line_str.c \
	./srcs/parse/parse_utils/ft_atod_index_dev.c \
	./srcs/parse/parse_utils/ft_atoi_index.c \
	./srcs/parse/parse_utils/inclement_ij.c \
	./srcs/parse/parse_utils/is_start_str.c \
	./srcs/parse/parse_utils/skip_and_set.c \
	./srcs/parse/parse_utils/skip_space.c \
	./srcs/parse/rt/parse_rt.c \
	./srcs/parse/rt/parse_txt.c \
	./srcs/parse/setter/set_brightness.c \
	./srcs/parse/setter/set_color.c \
	./srcs/parse/setter/set_coordinate.c \
	./srcs/parse/setter/set_diameter.c \
	./srcs/parse/setter/set_fov.c \
	./srcs/parse/setter/set_height.c \
	./srcs/parse/setter/set_radius.c \
	./srcs/parse/setter/set_vector.c \
	./srcs/ray/generate_ray.c \
	./srcs/ray/get_hit_color.c \
	./srcs/ray/hit/hit_cylinder.c \
	./srcs/ray/hit/hit_cylinder_body.c \
	./srcs/ray/hit/hit_cylinder_caps.c \
	./srcs/ray/hit/hit_plane.c \
	./srcs/ray/hit/hit_sphere.c \
	./srcs/ray/hit_object_list.c \
	./srcs/ray/set_ray.c \
	./srcs/render/render.c \
	./srcs/rt_generate_color.c \
	./srcs/rt_put_back_ground.c \
	./srcs/shadow/is_shadow.c \
	./srcs/utils/error/error_ambient.c \
	./srcs/utils/error/error_brightness.c \
	./srcs/utils/error/error_color.c \
	./srcs/utils/error/error_coordinate.c \
	./srcs/utils/error/error_cylinder.c \
	./srcs/utils/error/error_fov.c \
	./srcs/utils/error/error_message.c \
	./srcs/utils/error/error_message_parse.c \
	./srcs/utils/error/error_message_value.c \
	./srcs/utils/error/error_radius.c \
	./srcs/utils/error/error_vector.c \
	./srcs/utils/error/error_message_common.c \
	./srcs/utils/free/free_ambient.c \
	./srcs/utils/free/free_camera.c \
	./srcs/utils/free/free_color.c \
	./srcs/utils/free/free_light.c \
	./srcs/utils/free/free_object.c \
	./srcs/utils/free/free_object_list.c \
	./srcs/utils/free/free_ray.c \
	./srcs/utils/free/free_split.c \
	./srcs/utils/free/free_vector.c \
	./srcs/utils/free/free_rt.c \
	./srcs/utils/free/free_txt.c \
	./srcs/utils/printers/rt_print_ambient.c \
	./srcs/utils/printers/rt_print_camera.c \
	./srcs/utils/printers/rt_print_color.c \
	./srcs/utils/printers/rt_print_cylinder.c \
	./srcs/utils/printers/rt_print_indent.c \
	./srcs/utils/printers/rt_print_light.c \
	./srcs/utils/printers/rt_print_list.c \
	./srcs/utils/printers/rt_print_ntp.c \
	./srcs/utils/printers/rt_print_object.c \
	./srcs/utils/printers/rt_print_object_type.c \
	./srcs/utils/printers/rt_print_plane.c \
	./srcs/utils/printers/rt_print_rt.c \
	./srcs/utils/printers/rt_print_sphere.c \
	./srcs/utils/printers/rt_print_str.c \
	./srcs/utils/printers/rt_print_vector.c \
	./srcs/utils/printers/rt_print_with_indent.c \
	./srcs/vector/vec_add.c \
	./srcs/vector/vec_add3.c \
	./srcs/vector/vec_cross.c \
	./srcs/vector/vec_dot.c \
	./srcs/vector/vec_len.c \
	./srcs/vector/vec_mul.c \
	./srcs/vector/vec_normalize.c \
	./srcs/vector/vec_scale.c \
	./srcs/vector/vec_sub.c \
	./srcs/calc_diffuse_reflection_radiance.c \
	./srcs/calc_radiance.c


# ディレクトリ設定
OBJ_DIR     := ./obj
LIBFT_DIR   := libft
GNL_DIR   := gnl
MLX_DIR     := minilibx-linux

# ライブラリ
LIBFT_LIB   := $(LIBFT_DIR)/libft.a
MLX_LIB     := $(MLX_DIR)/libmlx.a

# オブジェクトファイルのパスを構築
OBJS        := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
DEPENDS     := $(OBJS:.o=.d)

# コンパイラ設定
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -MMD -MP
INC         := -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR)

# リンクオプション
LD_FLAGS    := -L$(LIBFT_DIR) -L$(MLX_DIR) -L$(GNL_DIR)
LD_LIBS     := $(LIBFT_LIB) $(MLX_LIB) -lXext -lX11 -lm -lz -lreadline

# ================================
# Main targets
# ================================

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(GNL_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LD_FLAGS) $(LD_LIBS) -o $@

# オブジェクトファイルのビルドルール
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# libft ビルド
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# MiniLibX ビルド
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)


# ================================
# Utilities
# ================================

debug: CFLAGS += -g -O0
debug: LDFLAGS += -g -O0
debug: all

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) -r $(GNL_DIR)/.dSYM || true

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR) || true
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(GNL_DIR) || true

re: fclean all

.PHONY: all clean fclean re

# ================================
# 依存ファイル読み込み
# ================================

-include $(DEPENDS)
