#include <stdio.h>
#include "push_swap.h"
int main(void)
{
	int i = -1;
	t_list *test = NULL;
	t_list *test2 = NULL;
	//initialize a non sorted t_list
	while(++i < 5)
	{
		if (!(i % 3))
			add_back(&test, get_new(i + 2 * 3, NULL));
		else if (!(i % 2))
			add_back(&test, get_new(i, NULL));
		else
			add_back(&test, get_new(i * 5, NULL));
	}
	//end of init
	//----------------
	//start of testing
	assign_stack(&test, get_smallest(test));
	test2 = test;
	while(test2)
	{
		ft_printf("[%d : %d] ", test2->pos, test2->nb);
		test2 = test2->next;
	}
	write(1,"\n",1);
	ft_printf("---------------------\n");
	display_list(test);
	rotate(&test);
	display_list(test);
	reverse_rotate(&test);
	display_list(test);
	
	ft_printf("---------------------\n");
	test2 = test;
	while(test2)
	{
		ft_printf("[%d : %d] ", test2->pos, test2->nb);
		test2 = test2->next;
	}
	write(1,"\n",1);
	t_list *iss;
	add_back(&iss, get_new(4, NULL));
	add_back(&iss, get_new(3, NULL));
	add_back(&iss, get_new(2, NULL));
	add_back(&iss, get_new(1, NULL));
	add_back(&iss, get_new(9, NULL));
	add_back(&iss, get_new(8, NULL));
	add_back(&iss, get_new(7, NULL));
	add_back(&iss, get_new(6, NULL));
	add_back(&iss, get_new(5, NULL));
	ft_printf("------------------------\n");
	display_list(iss);
	ft_printf("is it inverse soft sorted mes couilles en ski ? -> %d\n", is_soft_invert_sorted(iss));
}