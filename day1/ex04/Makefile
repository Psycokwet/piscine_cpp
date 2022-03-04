# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 22:36:55 by saray             #+#    #+#              #
#    Updated: 2022/03/04 10:21:20 by scarboni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= mySed

OBJ_PATH			= bin/

CXX 				= c++

CPPFLAGS 			= -W -Wall -Wextra -Werror -g3 -pedantic -std=c++98

SRC_PATH			= ./srcs/

SRCS = 	main.cpp



SRC_FILES	+=	$(SRCS)


SRC			= 	$(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ 		= 	$(addprefix $(OBJ_PATH), $(SRC_FILES:cpp=o))

OBJ_PATHS_INIT			= $(OBJ_PATH)

all: $(NAME)

$(OBJ_PATHS_INIT)	:
	@echo "Generating bin folder and subfolders" $@
	@mkdir -p  $@  

$(NAME): $(OBJ_PATHS_INIT)  $(OBJ)
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

RES_FILE	+=	exec_log.txt
test:	$(NAME)
	valgrind ./$(NAME) > $(RES_FILE)
	valgrind ./$(NAME) Makefile " " "%" >> $(RES_FILE)
	valgrind ./$(NAME) Pwett PATH PONEY >> $(RES_FILE)
	valgrind ./$(NAME) Makefile >> $(RES_FILE)
	valgrind ./$(NAME) Makefile PATH >> $(RES_FILE)
	valgrind ./$(NAME) srcs/main.cpp include "I'm a nice and sweet pony !" >> $(RES_FILE)
	valgrind ./$(NAME) srcs/main.cpp include "I'm a nice and sweet pony !" gdffdgdfg >> $(RES_FILE)

.PHONY: clean fclean re bonus