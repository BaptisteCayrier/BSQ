##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for lib.
##

SRC	=	my_putchar.c			\
		my_putstr.c			\
		my_put_nbr.c			\
		my_getnbr.c			\
		fs_open_file.c			\
		load_2d_arr_from_file.c		\
		load_file_in_mem.c		\
		mem_alloc_2d_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	compile

compile:	$(OBJ)
	ar rc libmy.a $(OBJ)
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
