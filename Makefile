NAME_CHECKER	= checker

NAME	= push_swap

all:	$(NAME)

$(NAME)	:
	gcc main.c ope.c ope2.c ope3.c utils.c utils2.c Libft/libft.a ft_printf/libftprintf.a -o $(NAME)

c	:	$(NAME_CHECKER)

$(NAME_CHECKER)	:
	gcc checker.c ope.c ope2.c ope3.c utils.c Libft/libft.a ft_printf/libftprintf.a get_next_line.c get_next_line_utils.c utils2.c -o $(NAME_CHECKER)

fclean	:
				rm -rf checker push_swap
				make