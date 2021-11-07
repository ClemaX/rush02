#include "rush02.h"

#include <stdio.h>
#include <limits.h>

int	best_move(plateau *grid, char player)
{
	int	score;
	int	best_score;
	int	best_move;

	best_score = INT_MIN;
	best_move = -1;

	for (int x = 0; x < grid->x; x++)
	{
		if (place(grid, x, player) != -1)
		{
			score = blob(*grid, player, BLOB_RESOLUTION);
			fprintf(stderr, "Score for position %d: %d\n", x, score);
			unplace(grid, best_move);
			if (score >= best_score)
			{
				best_score = score;
				best_move = x;
			}
		}
	}

	if (best_move == -1)
		fprintf(stderr, "No move is possible anymore!\n");

	return best_move;
}

int main(void)
{
	plateau	grid;
	int		ret;
	int		x;

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
			x = best_move(&grid, GRID_PLAYER_A);

			if (x == -1)
				break;

			send_pos(x);
			place(&grid, x, GRID_PLAYER_A);
			print_grid(&grid);

			ret = recv_pos(&x);
			if (ret == 0)
			{
				place(&grid, x, GRID_PLAYER_B);
				print_grid(&grid);
			}
		}
		clear_grid(&grid);
	}

	return 0;
}