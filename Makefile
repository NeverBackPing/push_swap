################# COMPILATION ###########################

CC =  cc
CFLAGS = -Wall -Werror -Wextra

################# COMMANDS ##############################

RM = rm -rf

################# FILES #################################

LIBFT = libft.a

LIBFT_DIR = libft

LIBC = libcft/ft_isalpha.c libcft/ft_isdigit.c libcft/ft_isalnum.c libcft/ft_isascii.c libcft/ft_isprint.c libcft/ft_strlen.c\
	libcft/ft_memset.c libcft/ft_bzero.c libcft/ft_memcpy.c libcft/ft_memmove.c libcft/ft_strlcat.c libcft/ft_strlcpy.c\
	libcft/ft_strchr.c libcft/ft_strrchr.c libcft/ft_strncmp.c libcft/ft_memchr.c libcft/ft_strnstr.c libcft/ft_toupper.c\
	libcft/ft_memcmp.c libcft/ft_tolower.c libcft/ft_atoi.c libcft/ft_calloc.c libcft/ft_strdup.c\
	libcft/ft_substr.c libcft/ft_strjoin.c libcft/ft_strtrim.c libcft/ft_itoa.c libcft/ft_strmapi.c libcft/ft_striteri.c\
	libcft/ft_putchar_fd.c libcft/ft_putstr_fd.c libcft/ft_putendl_fd.c libcft/ft_putnbr_fd.c libcft/ft_split.c\
	libcft/ft_lstnew_bonus.c libcft/ft_lstadd_front_bonus.c libcft/ft_lstsize_bonus.c libcft/ft_lstlast_bonus.c\
	libcft/ft_lstadd_back_bonus.c libcft/ft_lstdelone_bonus.c libcft/ft_lstclear_bonus.c libcft/ft_isspace.c\
	libcft/ft_lstiter_bonus.c libcft/ft_lstmap_bonus.c libcft/ft_atol.c libcft/ft_signe.c libcft/ft_isdigitsigne.c

LIBFT_OBJS = $(LIBC:.c=.o)

################# FILES #################################

PRINTF = libftprintf.a

PRINTF_DIR = printf

PRINTF_SRC =  printf/ft_converse_base.c printf/ft_hexa_base.c printf/size_hexa.c\
	printf/ft_hexa_lower.c  printf/ft_putchar.c printf/ft_putnbr.c printf/ft_printf.c\
	printf/ft_print_usigned.c printf/ft_putstr.c printf/ft_swap.c

PRINTF_OBJS = $(PRINTF_SRC:.c=.o)

#########################################################

NAME = push_swap

SRC = srcs/data_link.c srcs/parsing.c srcs/swap.c srcs/check.c srcs/single_data.c srcs/command.c srcs/road.c\
	 srcs/command_utile.c srcs/command_part2.c srcs/sort.c srcs/sort_part2.c srcs/sort_part3.c

SRCS = ${SRC} ${LIBC} ${PRINTF_SRC}

OBJS = $(SRCS:.c=.o)

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR)

#########################################################

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT): $(LIBFT_OBJS)
		ar rcs $(LIBFT) $(LIBFT_OBJS)

$(PRINTF): $(PRINTF_OBJS)
		ar rcs $(PRINTF) $(PRINTF_OBJS)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	 $(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) -L. -lft -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)

fclean: clean
	$(RM) $(LIBFT) $(PRINTF) $(NAME)

re: fclean all

.PHONY: all clean fclean re