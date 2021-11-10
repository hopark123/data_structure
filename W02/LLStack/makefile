NAME = LLStack

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
	LLStack.h \
)

SRC = $(addprefix $(SRC_DIR)/, \
	LLStack.c \
	LLStack_test.c \
)

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test : $(NAME)
	./LLStack
$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDES) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re test\
