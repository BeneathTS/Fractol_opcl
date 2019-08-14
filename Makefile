NAME = fractol

SRCS =	main.c \
		exit.c \
		check_input.c \
		init.c \
		hooks.c \
		opcl_init.c \
		draw_fractals.c \
		controls.c \
		errors.c \

OS = $(SRCS:.c=.o)

SRCDIR = sources

L_LIB = libft/libft.a

I_LIB = -I libft/includes

L_MLX = -L /usr/local/lib

I_MLX = -I /usr/local/include

I_FDF = -I includes

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -framework OpenCL

vpath %.c $(SRCDIR)

.PHONY: all lib clean fclean re clbash

all: lib $(NAME)

$(NAME): $(OS)
	@echo "\n==============================="
	@echo "       \033[1mFractol\033[0m Compiling"
	@echo "==============================="
	@sleep 0.2
	@gcc $(CFLAGS) $^ $(L_LIB) $(L_MLX) $(I_FDF) $(I_LIB) $(I_MLX) $(MLXFLAGS) -o $(NAME)
	@echo "\033[1;32mDone\033[0m!"

$(OS): $(SRCS)
	@gcc $(CFLAGS) -c $^ $(I_FDF) $(I_LIB) $(I_MLX)

lib:
	@make -C libft/

clean:
	@make -C libft/ clean
	@rm -f $(OS)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -f $(OS)
	@echo "\n==============================="
	@echo "       \033[1mFractol\033[0m Removing"
	@echo "==============================="
	@sleep 0.2
	@echo "\033[1;31mFractol removed!\033[0m"

re: fclean all

clterm: 
	@clear && printf '\033[3J'