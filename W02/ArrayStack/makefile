NAME = ArrayStack

CC = gcc
# CFLAGS = 
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -g3 -fsanitize=address
RM = rm
RMFLAGS = -f

SRC_DIR = .
INC_DIR = .
OBJ_DIR = obj

INCLUDE = $(addprefix $(INC_DIR)/, \
	ArrayStack.h \
)

SRC = $(addprefix $(SRC_DIR)/, \
	ArrayStack.c \
	ArrayStack_test.c \
)

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test : $(NAME)
	./ArrayStack
$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDE) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re test\
