# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 15:43:11 by cgangaro          #+#    #+#              #
#    Updated: 2021/09/22 12:10:03 by cgangaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
PATH		= 	srcs
SRCS_NAME	=	main.c \
				ft_split.c \
				ft_calloc.c \
				ft_memcpy.c \
				ft_bzero.c \
				ft_substr.c \
				ft_strlen.c \
				ft_strjoin.c \
				execve.c \
				here_doc.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_strchr.c \
				ft_strncmp.c \
				child.c
OBJS		= ${SRCS:.c=.o}
FLAGS		= -Wall -Werror -Wextra
SRCS		= $(addprefix ${PATH}/,${SRCS_NAME})
%.o: %.c ./inc/pipex.h
		gcc $(FLAGS) -c $< -o $@
all:	$(NAME)
$(NAME) : $(OBJS)
			gcc $(FLAGS) $(OBJS)  -o $(NAME)
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(OBJS) $(NAME)
norme:
	@norminette $(SRCS) inc/pipex.h