# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 19:21:40 by pbumidan          #+#    #+#              #
#    Updated: 2024/03/25 20:01:01 by pbumidan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRCS = \
	get_next_line_utils.c \
	get_next_line.c \
	get_all_lines.c \

OBJS := $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
	
all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $^ 
	@echo "$(GREEN)gnl compiled!$(NC)"

clean: 
	@rm -f $(OBJS)
	@echo "$(YELLOW)The gnl object files have been removed!$(NC)"

fclean: 
	@rm -f $(NAME) $(OBJS)
	@echo "$(YELLOW)All the gnl files have been removed!$(NC)"

re: fclean all

.PHONY: all clean fclean re

#colours
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
NC = \033[0m
