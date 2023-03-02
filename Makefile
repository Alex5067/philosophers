# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igoralekseev <igoralekseev@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 21:47:49 by igoraleksee       #+#    #+#              #
#    Updated: 2022/04/27 13:05:02 by igoraleksee      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = srcs/action.c \
	   srcs/init.c \
	   srcs/philo.c \
	   srcs/pars_args.c \
	   srcs/utils.c \
	   
	   
OBJS = ${SRC:.c=.o}
HEADER = philo.h
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
