################# COMPILATION ###########################

CC =  cc
CFLAGS = -Wall -Werror -Wextra

################# COMMANDS ##############################

RM = rm -rf

################# FILES #################################

LIBFT = libft.a

LIBFT_DIR = libft

LIBC = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_strlen.c\
	libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_strlcat.c libft/ft_strlcpy.c\
	libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_strnstr.c libft/ft_toupper.c\
	libft/ft_memcmp.c libft/ft_tolower.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_strdup.c\
	libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c\
	libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_split.c\
	libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c\
	libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c\
	libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c

LIBFT_OBJS = $(LIBC:.c=.o)

################# FILES #################################

PRINTF = libftprintf.a

PRINTF_DIR = printf

PRINTF_SRC =  printf/ft_converse_base.c printf/ft_hexa_base.c printf/size_hexa.c\
	printf/ft_hexa_lower.c  printf/ft_putchar.c printf/ft_putnbr.c printf/ft_printf.c\
	printf/ft_print_usigned.c printf/ft_putstr.c printf/ft_swap.c

PRINTF_OBJS = $(PRINTF_SRC:.c=.o)

#########################################################

SRC = srcs/swap.c

SRCS = ${SRC} ${LIBC} ${PRINTF_SRC}

OBJS = $(SRCS:.c=.o)

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR)

#########################################################

all: $(LIBFT) $(PRINTF) main

$(LIBFT): $(LIBFT_OBJS)
		ar rcs $(LIBFT) $(LIBFT_OBJS)

$(PRINTF): $(PRINTF_OBJS)
		ar rcs $(PRINTF) $(PRINTF_OBJS)

main: $(OBJS) $(LIBFT) $(PRINTF)
	 $(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) -L. -lft -lftprintf -o main

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)

fclean: clean
	$(RM) $(LIBFT) $(PRINTF) main

re: fclean all

.PHONY: all clean fclean re