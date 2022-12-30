# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 12:05:56 by fialexan          #+#    #+#              #
#    Updated: 2022/12/30 18:07:12 by fialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/
LIBFT = $(LIBFT_DIRECTORY)libft.a

MINILIBX_DIRECTORY = ./minilibx-linux/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a

HEADERS_LIST = fdf.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST = main.c map_utils.c file_checker.c window_management.c color.c coordinate.c
SOURCES_DIRECTORY = ./sources/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

CC = gcc
FLAGS = -Wall -Werror -Wextra -g3
LIBRARIES = -L$(LIBFT_DIRECTORY) -lft -L$(MINILIBX_DIRECTORY) -lmlx_Linux -lXext -lX11 -lm
INCLUDES = -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS) -I $(MINILIBX_HEADERS)

# COLORS

GREEN = \033[0;92m
RED = \033[0;91m
CYAN = \033[0;96m
BLUE = \033[0;94m
YELLOW = \033[0;93m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@echo "\n\nStarting compile, now have some $(BLUE)colorful $(RED)text $(YELLOW)slayyyy$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)object files$(RESET) were created and have come to free us, $(YELLOW)monkeys$(RESET) united."
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(NAME)$(RESET) was created, like $(BLUE)god$(RESET) intended"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(OBJECTS_DIRECTORY)$(RESET) was created"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS) 
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(CYAN)$(NAME): $(RESET)Creating $(GREEN)$(LIBFT)$(RESET)"
	@make -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(CYAN)$(NAME):$(RESET) Creating $(GREEN)$(MINILIBX)$(RESET) now a bunch of words will appear i have $(RED)no$(RESET) idea what they mean, but we $(YELLOW)roll$(RESET)"
	@make -sC $(MINILIBX_DIRECTORY)

clean:
	@make -sC $(LIBFT_DIRECTORY) clean
	#@make -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME): $(RED)$(OBJECTS_DIRECTORY)$(RESET) was deleted, *insert sadge emote*"
	@echo "$(CYAN)$(NAME): $(RED)object files$(RESET) deleted, it was like Voldemort said *FETUS DELETUS*"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(CYAN)$(NAME): $(RED)$(MINILIBX)$(RESET) was deleted"
	@rm -f $(LIBFT)
	@make -sC $(LIBFT_DIRECTORY) fclean
	@echo "$(CYAN)$(NAME): $(RED)$(LIBFT)$(RESET) was deleted"
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME): $(RED)$(NAME) $(RESET)was deleted"

re:
	@make fclean
	@make all

.PHONY	: re fclean clean all