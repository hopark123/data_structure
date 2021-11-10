NAME = linkedlist

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
	linkedlist.h \
)

SRC = $(addprefix $(SRC_DIR)/, \
	linkedlist.c \
	linkedTest.c \
)

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test : $(NAME)
	./linkedlist
$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDES) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ) $(CLIBR)

.PHONY: all clean fclean re test\
