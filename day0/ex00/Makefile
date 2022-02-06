# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 22:36:55 by saray             #+#    #+#              #
#    Updated: 2022/02/06 18:00:36 by scarboni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= Megaphone

OBJ_PATH			= bin/

CXX 				= clang++

CPPFLAGS 			= -W -Wall -Wextra -Werror -g3 -pedantic -std=c++98

SRC_PATH			= ./srcs/

SRCS = 	Megaphone.cpp

SRC_FILES	+=	$(SRCS)


SRC			= 	$(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ 		= 	$(addprefix $(OBJ_PATH), $(SRC_FILES:cpp=o))

OBJ_PATHS_INIT			= $(OBJ_PATH)

all: $(OBJ_PATHS_INIT)  $(NAME)


$(OBJ_PATHS_INIT)	:
	@echo "Generating bin folder and subfolders" $@
	@mkdir -p  $@  

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(HEADERS_FILES)
	${CXX} ${CPPFLAGS}   -c $< -o $@ 

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -rf $(OBJ_PATH)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -rf $(OBJ_PATH)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"		

re: fclean all

.PHONY: clean fclean re bonus