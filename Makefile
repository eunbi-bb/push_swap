NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC_DIR		= src/
OBJ_DIR		= obj/
HEADER		= push_swap.h
LIBFT		= libft

PUSH_SWAP_DIR	=	push_swap/
SRC_FILE		=	push_swap.c quick_sort.c sort.c push_swap_utils.c

OPER_DIR		=	operations/
OPER_FILE		=	push.c swap.c rotate.c reverse_rotate.c

SRC_FILES	=	$(addprefix $(PUSH_SWAP_DIR), $(SRC_FILE))
OPER_FILES	=	$(addprefix $(OPER_DIR), $(OPER_FILE))

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
OPER_OBJ	=	$(addprefix $(OBJ_DIR), $(OPER_FILES:.c=.o))

OBJF =	.cache_exists

all: $(NAME)

$(NAME):	$(OBJ) $(OPER_OBJ) $(OBJF)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@$(CC) $(CFLAGS) $(OBJ) $(OPER_OBJ) -I inc libft.a -o $(NAME)
			@echo "- push_swap is compiled -"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER)| $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR)$(PUSH_SWAP_DIR)
		@mkdir -p $(OBJ_DIR)$(OPER_DIR)

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT)
		@rm -f $(OBJF)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)

re:	fclean all

.PHONY: all clean fclean re