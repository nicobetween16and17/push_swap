NAME_CHECKER	= checker

NAME	= push_swap

all:	$(NAME)

$(NAME)	:
	cd Libft && make re && cd .. && cd ft_printf && make re && cd ..
	gcc main.c ope.c ope2.c utils.c utils2.c sort.c sort2.c Libft/libft.a ft_printf/libftprintf.a -o $(NAME)

clean :
	rm -f *.o

fclean :
	make clean
	rm -f $(NAME)

re	:
	make fclean
	make