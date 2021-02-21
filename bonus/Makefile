##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	my_sokoban.c \
		my_move.c \
		fonc_ess.c \
		split.c \
		create_map.c \
		create_map2.c \

OBJS = $(SRCS:.c=.o)

NAME = my_sokoban

all : $(NAME)

$(NAME) :
	make -C lib/my
	gcc -g -o $(NAME) $(SRCS) -L lib/ -lmy -lncurses -I include
	make clean -C lib/my

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

x : re
	./$(NAME)