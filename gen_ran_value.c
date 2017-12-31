#include "Includes/push_swap.h"
#include <time.h>

static int	db_list_find(t_db_list *list, int x)
{
	t_db_list	*current;

	current = list;
	while (current)
	{
		if (current->data == x)
			return (1);
		current = current->next;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		x;
	int		nb;
	char		*str;
	t_db_list	*list;

	nb = ft_atoi(argv[1]);
	if (argc == 1 || nb <= 0)
		return (0);
	srand(time(NULL));
	x = (rand() % 700) - 200;
	list = NULL;
	db_push_back(&list, x);
	str = ft_itoa(x);
	nb--;
	x = (rand() % 700) - 200;
	while (nb)
	{
		while (db_list_find(list, x))
			x = (rand() % 700) - 200;
		nb--;
		db_push_back(&list, x);
		str = ft_strjoinfree(str, " ", 1);
		str = ft_strjoinfree(str, ft_itoa(x), 3);
		x = (rand() % 700) - 200;
	}
	ft_putendl(str);
	return (0);
}
