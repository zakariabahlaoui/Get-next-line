NAME = libft.a

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

OBJECT_FILES = get_next_line.o  ft_strchr.o ft_strjoin.o ft_strlen.o ft_strdup.o

all: my 

my: $(OBJECT_FILES)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)

fclean: clean 
	rm -f $(NAME)

re: fclean all