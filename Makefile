NAME		=	so_long
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
RM		=	rm -rf
SRC		= 	so_long map_fill map_format_chk arr_floodfill close_reopen identifiers
SRC_DIR		= 	srcs
SRCS		=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
OBJ_DIR		=	obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:=.o))
LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a


all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
		make -C $(LIBFT_PATH) all
clean:
		make -C $(LIBFT_PATH) clean
				$(RM) $(OBJ_DIR)
fclean: clean
		make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
