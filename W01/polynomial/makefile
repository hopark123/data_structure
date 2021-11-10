NAME = polynomial

CC = gcc
CFLAGS = 
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -g3 -fsanitize=address
RM = rm
RMFLAGS = -f

SRC_DIR = .
INC_DIR = .
OBJ_DIR = obj
vpath %.c $(SRC_DIR)

INCLUDE = $(addprefix $(INC_DIR)/, \
	polynomial.h \
)

SRC = $(addprefix $(SRC_DIR)/, \
	polynomial.c \
	polynomial_test.c \
)


all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test : $(NAME)
	./polynomial


OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
$(OBJ_DIR ) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(INCLUDE) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDE) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re test\
