##
## Makefile for Makefile in /home/loeb_t/rendu/cpp_plazza
## 
## Made by LOEB Thomas
## Login   <loeb_t@epitech.net>
## 
## Started on  Fri Apr 25 16:38:57 2014 LOEB Thomas
## Last update Tue Apr 29 15:08:03 2014 abgral_f
##

NAME	= plazza

F_SRC	= src/

F_INC	= inc/

SRC	= $(F_SRC)main.cpp		\
	  $(F_SRC)ACondVars.cpp		\
	  $(F_SRC)Americana.cpp		\
	  $(F_SRC)AMutex.cpp		\
	  $(F_SRC)ANamedPipe.cpp	\
	  $(F_SRC)APizza.cpp		\
	  $(F_SRC)AProcess.cpp		\
	  $(F_SRC)AThread.cpp		\
	  $(F_SRC)AThreadPool.cpp	\
	  $(F_SRC)AUI.cpp		\
	  $(F_SRC)CondVars.cpp		\
	  $(F_SRC)Cook.cpp		\
	  $(F_SRC)Factory.cpp		\
	  $(F_SRC)Fantasia.cpp		\
	  $(F_SRC)Ingredient.cpp	\
	  $(F_SRC)Kitchen.cpp		\
	  $(F_SRC)Margarita.cpp		\
	  $(F_SRC)Mutex.cpp		\
	  $(F_SRC)NamedPipe.cpp		\
	  $(F_SRC)Order.cpp		\
	  $(F_SRC)Pizza.cpp		\
	  $(F_SRC)Plazza.cpp		\
	  $(F_SRC)Process.cpp		\
	  $(F_SRC)Reception.cpp		\
	  $(F_SRC)Regina.cpp		\
	  $(F_SRC)Thread.cpp		\
	  $(F_SRC)Parser.cpp		\

OBJ	= $(SRC:.cpp=.o)

CPPFLAGS= -W -Wall -Werror -Wextra -I$(F_INC)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) -lpthread

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
