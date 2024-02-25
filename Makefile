# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbumidan <pbumidan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 19:21:40 by pbumidan          #+#    #+#              #
#    Updated: 2024/02/25 17:20:53 by pbumidan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

LIBH = get_next_line.h

SRCS = \
	get_next_line_utils.c \
	get_next_line.c \
	get_all_lines.c \

OBJS := $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c $(LIBH) 
	cc $(CFLAGS) -c $< -o $@  -I $(LIBH)
	
$(NAME): $(OBJS) $(LIBH)
	ar -rcs $(NAME) $^ 
	@echo "$(GREEN)gnl compiled!$(NC)"

all: $(NAME)

clean: 
	rm -f $(OBJS)
	@echo "$(YELLOW)The gnl object files have been removed!$(NC)"

fclean: 
	rm -f $(NAME) $(OBJS)
	@echo "$(YELLOW)All the gnl files have been removed!$(NC)"

re: fclean all

.PHONY: all clean fclean re

#colours
GREEN = \033[0;92m
YELLOW = \033[0;93m
CYAN = \033[0;96m
NC = \033[0m