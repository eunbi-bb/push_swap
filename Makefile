NAME		= push_swap

CC			= gcc
ifdef DEBUG
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g 
else
CFLAGS		= -Wall -Wextra -Werror
endif
SRC_DIR		= src/
OBJ_DIR		= obj/
HEADER		= push_swap.h
LIBFT		= libft

PUSH_SWAP_DIR	=	push_swap/
SRC_FILE		=	push_swap.c radix.c sort.c sort_utils.c push_swap_utils.c node_utils.c

OPER_DIR		=	operations/
OPER_FILE		=	push.c swap.c rotate.c reverse_rotate.c

SRC_FILES	=	$(addprefix $(PUSH_SWAP_DIR), $(SRC_FILE))
OPER_FILES	=	$(addprefix $(OPER_DIR), $(OPER_FILE))

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
OPER_OBJ	=	$(addprefix $(OBJ_DIR), $(OPER_FILES:.c=.o))

OBJF =	.cache_exists

CYAN_B		=	\033[1;96m
CYAN		=	\033[0;96m

all: $(NAME)

$(NAME):	$(OBJ) $(OPER_OBJ) $(OBJF)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(CC) $(CFLAGS) $(OBJ) $(OPER_OBJ) libft/libft.a -o $(NAME)
			@echo "$(CYAN_B)- push_swap is compiled -"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER)| $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR)$(PUSH_SWAP_DIR)
		@mkdir -p $(OBJ_DIR)$(OPER_DIR)
		@touch $(OBJF)

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT)
		@rm -f $(OBJF)
		@echo "$(CYAN)- Object files are cleaned -"

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)
		@echo "$(CYAN)- Executable files are cleaned -"

re:	fclean all

.PHONY: all clean fclean re