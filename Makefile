COMPILE = gcc
FLAGS = -Wall -Wextra -Werror
MINILIBX = minilibx/libmlx_Linux.a -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm
MYLIBFT = mylibft/*.a
NAME = fdf

all: $(NAME)
$(NAME):
	$(COMPILE) $(FLAGs) *.c $(MINILIBX) $(MYLIBFT) -o $(NAME)
clean:
	rm -f *.o
fclean: clean
	rm fdf
re: fclean all
t: re
	./fdf test.fdf
.PHONY: all object clean fclean re t
