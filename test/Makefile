# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 19:10:49 by mbaron            #+#    #+#              #
#    Updated: 2018/01/29 13:10:08 by mbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test_gnl

DIR			=	.

DIR_GNL		=	..

DIR_LIB		=	$(DIR_GNL)/libft

LIB			=	-L$(DIR_LIB) -lft

HEADERS		=	-I $(DIR)				\
				-I $(DIR_GNL)			\
				-I $(DIR_LIB)/includes

SRCS		=	$(DIR)/main.c			\
				$(DIR_GNL)/get_next_line.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra

CC			=	gcc

RM			=	rm -f

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(MAKE) -C $(DIR_LIB)
				$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(HEADERS) $(LIB)

%.o			:	%.c
				$(CC) -o $@ -c $< $(CFLAGS) $(HEADERS)

clean		:
				$(MAKE) -C $(DIR_LIB) clean
				$(RM) $(OBJS)

fclean		:	clean
				$(MAKE) -C $(DIR_LIB) fclean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
