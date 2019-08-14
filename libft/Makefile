# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 22:01:04 by ahiroko           #+#    #+#              #
#    Updated: 2019/05/18 16:00:45 by ahiroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c \
		ft_strdup.c \
		ft_strstr.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isalpha.c \
		ft_atoi.c \
		ft_ss.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstsize.c \
		ft_sqrt.c \
		ft_abs.c \
		ft_isblank.c \
		ft_strswap.c \
		ft_strjoinfree.c \
		ft_strchrdup.c \
		get_next_line.c \

OS = $(SRCS:.c=.o)

INCLDS = includes/

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@echo "\n==============================="
	@echo "       \033[1mLibft\033[0m Compiling"
	@echo "==============================="
	@gcc -c $(FLAGS) -I $(INCLDS) $(SRCS) 
	@ar rc $(NAME) $(OS)
	@echo "\033[1;32mDone\033[0m!"

all: $(NAME)

clean:
	@rm -f $(OS)

fclean: clean
	@rm -f $(NAME)
	@echo "\n==============================="
	@echo "       \033[1mLibft\033[0m Removing"
	@echo "==============================="
	@sleep 0.2
	@echo "\033[1;31mLibft removed!\033[0m"

re: fclean $(NAME)
