FILES = main
OFILES = $(addsuffix .o, $(FILES))
FLAGS = -Wall -Wextra -Werror
COMP = gcc
NAME = a.out

all: $(NAME)

$(NAME): $(OFILES)
	$(COMP) -o $(NAME) $(OFILES)

%.o: %.c
	$(COMP) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re