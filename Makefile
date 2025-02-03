SRC = 	mandatory/so_long.c  mandatory/utils/parse.c mandatory/utils/parse_1.c mandatory/utils/render.c mandatory/utils/key_handling.c \
		mandatory/utils/find.c mandatory/utils/check_win.c mandatory/utils/moves.c \
		mandatory/utils/find_1.c mandatory/utils/utils.c mandatory/utils/check_path.c\
		\
		ft_printf/ft_printf.c ft_printf/check_specifier.c ft_printf/ft_putstr.c ft_printf/ft_putchar.c ft_printf/ft_hex_addr.c \
		ft_printf/ft_putnbr.c ft_printf/ft_putun.c ft_printf/ft_low_hex.c ft_printf/ft_up_hex.c Libft/ft_isalpha.c Libft/ft_isdigit.c \
		\
		Libft/ft_memset.c  Libft/ft_isalnum.c Libft/ft_isascii.c Libft/ft_isprint.c Libft/ft_strlen.c Libft/ft_bzero.c Libft/ft_memcpy.c \
		Libft/ft_memmove.c Libft/ft_strlcpy.c Libft/ft_strlcat.c Libft/ft_toupper.c Libft/ft_tolower.c Libft/ft_strchr.c Libft/ft_strrchr.c \
		Libft/ft_strncmp.c Libft/ft_memchr.c Libft/ft_memcmp.c Libft/ft_strnstr.c Libft/ft_atoi.c Libft/ft_calloc.c Libft/ft_strdup.c \
		Libft/ft_substr.c Libft/ft_strjoin.c Libft/ft_strtrim.c Libft/ft_split.c Libft/ft_itoa.c Libft/ft_strmapi.c Libft/ft_striteri.c \
		Libft/ft_putchar_fd.c Libft/ft_putstr_fd.c Libft/ft_putendl_fd.c Libft/ft_putnbr_fd.c Libft/ft_lstnew_bonus.c Libft/ft_lstadd_front_bonus.c \
		Libft/ft_lstsize_bonus.c Libft/ft_lstlast_bonus.c Libft/ft_lstadd_back_bonus.c Libft/ft_lstdelone_bonus.c Libft/ft_lstclear_bonus.c \
		Libft/ft_lstiter_bonus.c Libft/ft_lstmap_bonus.c

BONS =	bonus/so_long_bonus.c  bonus/utils/parse_bonus.c bonus/utils/parse_1_bonus.c bonus/utils/render_bonus.c bonus/utils/key_handling_bonus.c \
		bonus/utils/find_bonus.c bonus/utils/check_win_bonus.c bonus/utils/moves_bonus.c bonus/utils/enemy_patrol_bonus.c \
		bonus/utils/find_1_bonus.c bonus/utils/utils_bonus.c bonus/utils/check_path.c \
		\
		ft_printf/ft_printf.c ft_printf/check_specifier.c ft_printf/ft_putstr.c ft_printf/ft_putchar.c ft_printf/ft_hex_addr.c \
		ft_printf/ft_putnbr.c ft_printf/ft_putun.c ft_printf/ft_low_hex.c ft_printf/ft_up_hex.c Libft/ft_isalpha.c Libft/ft_isdigit.c \
		\
		Libft/ft_memset.c  Libft/ft_isalnum.c Libft/ft_isascii.c Libft/ft_isprint.c Libft/ft_strlen.c Libft/ft_bzero.c Libft/ft_memcpy.c \
		Libft/ft_memmove.c Libft/ft_strlcpy.c Libft/ft_strlcat.c Libft/ft_toupper.c Libft/ft_tolower.c Libft/ft_strchr.c Libft/ft_strrchr.c \
		Libft/ft_strncmp.c Libft/ft_memchr.c Libft/ft_memcmp.c Libft/ft_strnstr.c Libft/ft_atoi.c Libft/ft_calloc.c Libft/ft_strdup.c \
		Libft/ft_substr.c Libft/ft_strjoin.c Libft/ft_strtrim.c Libft/ft_split.c Libft/ft_itoa.c Libft/ft_strmapi.c Libft/ft_striteri.c \
		Libft/ft_putchar_fd.c Libft/ft_putstr_fd.c Libft/ft_putendl_fd.c Libft/ft_putnbr_fd.c Libft/ft_lstnew_bonus.c Libft/ft_lstadd_front_bonus.c \
		Libft/ft_lstsize_bonus.c Libft/ft_lstlast_bonus.c Libft/ft_lstadd_back_bonus.c Libft/ft_lstdelone_bonus.c Libft/ft_lstclear_bonus.c \
		Libft/ft_lstiter_bonus.c Libft/ft_lstmap_bonus.c

NAME = so_long

NAME_BONS = so_long_bonus

OBJ = $(SRC:.c=.o)

OBJ_BONS = $(BONS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

%.o: %.c so_long.h
	$(CC) -c $(CFLAGS) -Imlx $< -o $@

$(NAME): $(SRC) $(OBJ)
	$(CC) $(CFLAGS) -lmlx -framework OpenGl -framework AppKit $(SRC) -o $(NAME)

bonus : $(NAME_BONS)

$(NAME_BONS): $(BONS) $(OBJ_BONS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGl -framework AppKit $(BONS) -o $(NAME_BONS)

clean:
	rm -f $(OBJ) $(OBJ_BONS)

fclean: clean
	rm -f $(NAME) $(NAME_BONS)

re: fclean all

.PHONY: clean fclean re bonus