NAME_CHECKER	= checker

NAME	= push_swap

all:	$(NAME)

$(NAME)	:
	cd Libft && make re && cd .. && cd ft_printf && make re && cd ..
	gcc main.c ope.c ope2.c utils.c utils2.c sort.c Libft/libft.a ft_printf/libftprintf.a -o $(NAME)

c	:	$(NAME_CHECKER)

$(NAME_CHECKER)	:
	cd Libft && make re && cd .. && cd ft_printf && make re && cd ..
	gcc checker.c ope.c ope2.c utils.c Libft/libft.a ft_printf/libftprintf.a get_next_line.c get_next_line_utils.c utils2.c -o $(NAME_CHECKER)

re	:
	rm -rf push_swap
	make