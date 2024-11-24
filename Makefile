NAME = fractol

SRC_DIR = src
OUT_DIR = out

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

VPATH = $(SRC_DIR):$(SRC_DIR)/handlers:$(SRC_DIR)/fractals:$(SRC_DIR)/events

# Main program sources
SRCS = main.c \
		julia.c \
		mandelbrot.c \
		keypress.c \
		scrolling.c \
		input_handler.c \
		view.c


# Object files
OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -fsanitize=address
INCLUDES = -I$(LIBFT_DIR)/includes -I. -Iincludes -IMLX42/include/MLX42

MLXFLAGS = -L/opt/homebrew/opt/glfw/lib -lglfw -framework OpenGL

all: MLX42 $(NAME)

bonus: all

# Create output directory
$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OUT_DIR) $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) ./MLX42/build/libmlx42.a $(MLXFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

# Compile source files
$(OUT_DIR)/%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		rm -rf $(OUT_DIR)
		@make -C $(LIBFT_DIR) clean
		rm -rf MLX42


fclean: clean
		rm -f $(NAME)
		@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re