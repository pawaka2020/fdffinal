COMPILE = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MINILIBX = minilibx/libmlx_Linux.a -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm
MYLIBFT = mylibft/*.a
NAME = fdf

all: $(NAME)
$(NAME):
	$(COMPILE) $(FLAGS) *.c $(MINILIBX) $(MYLIBFT) -o $(NAME)
clean:
	rm fdf
fclean: clean
re: fclean all
t: re
	./fdf test.fdf
.PHONY: all object clean fclean re t
