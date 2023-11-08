NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRC_DIR = sources
INC_DIR = includes
SRCS =  ft_atoi.c ft_valid2.c search_and_fill.c ft_valid.c ft_filereader.c ft_filehandeling.c ft_board.c main.c
OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I./$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
	
