##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for pushswap.
##

SRC	=	src/display_map.c	\
		src/map_size.c		\
		src/exception.c		\
		src/bsq.c

M_SRC	=	src/main.c

T_SRC	=	tests/UnitTest.c

OBJ	=	$(M_SRC:.c=.o) $(SRC:.c=.o)

T_OBJ	=	$(T_SRC:.c=.o) $(SRC:.c=.o)

NAME	=	bsq

T_NAME	=	tests_run

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -I ./lib/my/

LDFLAGS	=	-lcriterion

LIB	=	-L. lib/my/libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

tests_run:	 $(T_OBJ)
	make -C lib/my
	$(CC) -o $(T_NAME) $(T_OBJ) $(LIB) $(LDFLAGS) $(CFLAGS)
	./$(T_NAME)

clean:
	rm -f $(OBJ)
	rm -f $(T_OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(T_NAME)
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete

re:	fclean all
