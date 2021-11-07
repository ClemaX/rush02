#include "rush02.h"

int main(void)
{
	plateau  	grid;
	int		  	ret;
	unsigned	x;

	ret = setup(&grid);

	if (ret == 0)
	{
		if (grid.player_b_starts)
		{
			ret = recv_pos(&x);
			if (ret == 0)
			{
				place(&grid, x, GRID_PLAYER_B);
				print_grid(&grid);
			}
		}
		while (ret == 0)
		{
			// TODO: Get best move
			send_pos(x);
			//if (ret == 0)
			{
				place(&grid, x, GRID_PLAYER_A);
				print_grid(&grid);

				ret = recv_pos(&x);
				if (ret == 0)
				{
					place(&grid, x, GRID_PLAYER_B);
					print_grid(&grid);
				}
			}
		}
		clear_grid(&grid);
	}

	return 0;
}
