# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 22:36:55 by saray             #+#    #+#              #
#    Updated: 2022/03/13 20:44:19 by scarboni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= executable

OBJ_PATH			= bin/

CXX 				= c++

CPPFLAGS 			= -Wall -Wextra -Werror -g3 -std=c++98

SRC_PATH			= ./srcs/

SRCS = 	main.cpp \
		Converter.cpp \
		# Convert.cpp


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

# LEAKS = valgrind 
LEAKS = 

test:	$(NAME)
	$(LEAKS) ./$(NAME) A
	$(LEAKS) ./$(NAME) m
	$(LEAKS) ./$(NAME) 0
	$(LEAKS) ./$(NAME) -0
	$(LEAKS) ./$(NAME) +0
	$(LEAKS) ./$(NAME) 1
	$(LEAKS) ./$(NAME) 42
	$(LEAKS) ./$(NAME) -42
	$(LEAKS) ./$(NAME) 1.42
	$(LEAKS) ./$(NAME) 0.0
	$(LEAKS) ./$(NAME) -0.0
	$(LEAKS) ./$(NAME) +0.0
	$(LEAKS) ./$(NAME) -90.04
	$(LEAKS) ./$(NAME) nan
	$(LEAKS) ./$(NAME) nanf
	$(LEAKS) ./$(NAME) -inf
	$(LEAKS) ./$(NAME) -inff
	$(LEAKS) ./$(NAME) +inf
	$(LEAKS) ./$(NAME) +inff
	$(LEAKS) ./$(NAME) +++---inff
	$(LEAKS) ./$(NAME) +++inff
	$(LEAKS) ./$(NAME) 46565465454765754357

.PHONY: clean fclean re bonus