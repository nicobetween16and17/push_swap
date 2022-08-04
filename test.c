#include <stdio.h>
#include "push_swap.h"
int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	int		op;
	static int	nb;
	if (!nb)
		nb = 1;
	b = NULL;
	if (ac == 1)
		return (0);
	a = get_stack(av, 0, 0);
	assign_stack(&a, get_smallest(a));
	display_list(a);
	int *pushb = to_push(a, 0,0, size(a));
	display_list(a);
	int i = -1;
	while (++i < 50)
		ft_printf("[%d]", pushb[i]);
	ft_printf("\n");
}