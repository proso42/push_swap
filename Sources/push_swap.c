#include "../Includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	info;

	info.list_a = NULL;
	info.list_b = NULL;
	info.cmd_list = NULL;
	if (!(check_argv(&info, argv, argc)))
		return (0);
	print_db_list_ab(info.list_a, info.list_b);		
	return (0);
}
