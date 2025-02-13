# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 15:57:43 by vfidelis          #+#    #+#              #
#    Updated: 2025/02/12 23:47:19 by vfidelis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMP = cc
FLAGS = -Wall -Wextra -Werror

FILEC = gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		parsing.c \
		main.c

NAME_OBJS = $(FILEC:.c=.o)

REMO = rm -rf

CREATE_LIB = ar -rcs


all: $(NAME)
	
$(NAME): $(NAME_OBJS)
	$(CREATE_LIB) $(NAME) $(NAME_OBJS)

.o: .c 
	$(COMP) $(FLAGS) -I ./ -c $< -o $@
	
clean:
	@$(REMO) $(NAME_OBJS)
	
fclean: clean
	@$(REMO) $(NAME)


re: fclean all

.PHONY: all clean fclean re