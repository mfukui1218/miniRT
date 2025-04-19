NAME        := miniRT

# ソースファイル（パス付き）
SRCS = $(shell find . -name "*.c" -not -path "*$(LIBFT_DIR)/*" -not -path "*$(MLX_DIR)/*")

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
debug:

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
