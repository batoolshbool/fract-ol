NAME        = fractol

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = src
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

INCLUDES    = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

SRCS        = $(SRC_DIR)/events.c \
              $(SRC_DIR)/fractol.c \
              $(SRC_DIR)/render_fractol.c \
              $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/utils2.c \
			  $(SRC_DIR)/mandelbrot_and_julia.c \
			   $(SRC_DIR)/burning_ship_bonus.c

OBJS        = $(SRCS:.c=.o)

LDFLAGS     = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning MiniLibX..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then make -C $(MLX_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
