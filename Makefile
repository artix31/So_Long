NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
FLAGS		=	-lmlx -lXext -lX11 -lm -I.
RM			=	rm -rf
SRC			=	so_long initiate map_file_chk \
				map_utility map_checker\
				movement rendering window_manager extra_chk \

SRCS		=	$(addsuffix .c, $(SRC))
OBJ_DIR		=	obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:=.o))
LIBFT_PATH	=	./Libft
LIBFT		=	$(LIBFT_PATH)/libft.a

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(FLAGS) -o $(NAME)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
		make -C $(LIBFT_PATH) all
clean:
		make -C $(LIBFT_PATH) clean
				@$(RM) $(OBJ_DIR)
fclean: clean
		make -C $(LIBFT_PATH) fclean
				@$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
