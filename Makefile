NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
OBJ_DIR		= obj/
HEADER		= push_swap.h
LIBFT		= /libft

SRC			=	push_swap.c quick_sort.c sort.c push_swap_utils.c
OPER_DIR	=	/operations
OPER_FILES	=	push.c swap.c rotate.c reverse_rotate.c

OBJ	=	$(addprefix $(OBJ_DIR), $(FORMATS:.c=.o))

OBJF =	.cache_exists

all: $(NAME)

$(NAME):	$(OBJ)
			@cd ./$(LIBFT) && make
			@cp $(LIBFT)/libft.a .
			@mv libft.a $(NAME)
			@ar -rcs $(NAME) $(OBJ)
			@echo "- push_swap is compiled -"

$(OBJ_DIR)%.o: %.c $(HEADER)| $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT)

fclean: clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)/libft.a

re:	fclean all

.PHONY: all clean fclean re