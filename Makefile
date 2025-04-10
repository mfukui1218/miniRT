NAME			:=	miniRT

SRCS			:=	main.c \
					init.c \

					

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
OBJ_DIR			:=	./obj
OBJS			:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR		:=	srcs/libft
LD_FLAGS		:=	-L$(LIBFT_DIR)
LD_LIBS			:=	-lft -lreadline 
INC				:=	-Iincludes -I$(LIBFT_DIR) -MMD -MP

vpath %.c	./srcs:./srcs/main:./srcs/init:./srcs/math:./srcs/mlx:./srcs/parse:./srcs/render:./srcs/utils:

$(NAME) : $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LD_FLAGS) $(LD_LIBS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_DIR)/libft.a: $(LIBFT_DIR)
	$(MAKE) complete -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all:	$(NAME)z

clean:
	$(RM) -r $(OBJS) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(NAME) 
	$(MAKE) fclean -C $(LIBFT_DIR)

re:	fclean all

.PHONY:	all clean fclean re
