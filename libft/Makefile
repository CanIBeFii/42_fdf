# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 12:27:56 by fialexan          #+#    #+#              #
#    Updated: 2022/12/30 18:00:16 by fialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -c -g

INCLUDES = -I $(HEADERS_DIRECTORY)

HEADERS_LIST = libft.h
HEADERS_DIRECTORY = includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST =ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isalnum.c ft_isprint.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_substr.c ft_tolower.c \
		ft_toupper.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strnstr.c \
		ft_strdup.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_atoi.c ft_split.c ft_findchar.c \
		get_next_line.c convert_hex.c format_c.c format_d.c \
		format_i.c format_p.c format_s.c format_u.c format_x_big.c \
		format_x_small.c ft_printf.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SOURCES_DIRECTORY = sources/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;92m
RED = \033[0;91m
CYAN = \033[0;96m
BLUE = \033[0;94m
RESET = \033[0m

# RULES

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(CYAN)$(NAME):$(RESET) $(GREEN)objects$(RESET) files were created"
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(NAME)$(RESET) was created"
	
$(OBJECTS_DIRECTORY):
	@echo "Going to compile the files, let's hope nothing breaks:"
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "	$(CYAN)$(NAME):$(RESET) $(GREEN)$(OBJECTS_DIRECTORY)$(RESET) was created"
	@echo "Each point shows the amount of disappointment that my parents have of me:"
	
$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@echo "Cleaning all the random files that you think that work:"
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "	$(CYAN)$(NAME):$(RESET) $(RED)$(OBJECTS_DIRECTORY)$(RESET) was deleted"
	@echo "	$(CYAN)$(NAME):$(RESET) $(RED)object files$(RESET) were annihilated"
	
fclean: clean
	@echo "Deep cleaning all the trash you created:"
	@rm -f $(NAME)
	@echo "	$(CYAN)$(NAME):$(RESET) $(RED)$(NAME)$(RESET) was erased from the world surface"

re:
	@make fclean
	@make all

.PHONY:
	all clean fclean re
