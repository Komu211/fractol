NAME = fractol

SRC_DIR = src
OUT_DIR = out

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a



VPATH = $(SRC_DIR)

# Main program sources
SRCS = main.c


# Object files
OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast 
INCLUDES = -I$(LIBFT_DIR)/includes -I. -IMLX42

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


fclean: clean
		rm -f $(NAME)
		@make -C $(LIBFT_DIR) fclean
		rm -rf MLX42


re: fclean all

.PHONY: all bonus clean fclean re