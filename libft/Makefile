# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 17:48:03 by rolemass          #+#    #+#              #
#    Updated: 2016/11/30 21:13:28 by rolemass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = 	ft_isascii.c \
		ft_lstnew.c	\
		ft_putchar.c \
		ft_strchr.c	\
		ft_strjoin.c \
		ft_strnew.c \
		ft_isdigit.c \
		ft_memalloc.c \
		ft_putchar_fd.c \
		ft_strclr.c	\
		ft_strlcat.c \
		ft_strnstr.c \
		ft_lstmap.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_putendl.c \
		ft_strcmp.c	\
		ft_strlen.c	\
		ft_strrchr.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_putendl_fd.c \
		ft_strcpy.c	\
		ft_strmap.c	\
		ft_strsplit.c \
		ft_atoi.c \
		ft_lstadd.c	\
		ft_memcmp.c	\
		ft_putnbr.c	\
		ft_strdel.c \
		ft_strmapi.c \
		ft_strstr.c \
		ft_bzero.c \
		ft_lstdel.c	\
		ft_memcpy.c	\
		ft_putnbr_fd.c \
		ft_strdup.c	\
		ft_strncat.c \
		ft_strsub.c \
		ft_lstdelone.c \
		ft_memdel.c	\
		ft_putstr.c	\
		ft_strequ.c	\
		ft_strncmp.c \
		ft_strtrim.c \
		ft_isalnum.c \
		ft_lstiter.c \
		ft_memmove.c \
		ft_putstr_fd.c \
		ft_striter.c \
		ft_strncpy.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_memset.c	\
		ft_strcat.c	\
		ft_striteri.c \
		ft_strnequ.c \
		ft_toupper.c \
		ft_lst_len.c \
		ft_lst_replace_at.c \
		ft_lst_push_back.c \
		ft_lst_link_with.c \
		ft_lst_split_argv.c \
		ft_lst_push_front.c \
		ft_create_elem.c \
		ft_lst_push_at.c \
		ft_lst_unlink.c \
		ft_init_head.c \
		ft_lst_replace.c \
		ft_print_str_lst.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a
INCLUDES = libft.h

all: $(NAME)

$(NAME):
	$(CC) -I $(INCLUDES) $(FLAGS) $(SRCS) -c
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all