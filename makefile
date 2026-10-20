NAME = ft_ping

CC = cc -Wall -Werror -Wextra

$(NAME): ft_ping.c
	$(CC) $^ -o $@

all: $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean