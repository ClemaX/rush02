#include "rush02.h"

#include <stdio.h>
#include <limits.h>

int	best_move(plateau *grid, char player, unsigned blob_resolution)
{
	int	score;
	int	best_score;
	int	best_move;

	score = 0;
	best_score = INT_MIN;
	best_move = -1;

	for (int x = 0; x < grid->x; x++)
	{
		score = blob(*grid, player, blob_resolution, x);
		if (score >= best_score)
		{
			best_score = score;
			best_move = x;
		}
	}

	if (best_move == -1)
		fprintf(stderr, "No move is possible anymore!\n");

	return best_move;
}

int main(void)
{
	plateau		grid;
	int			ret;
	int			x;
	unsigned	blob_resolution;

	ret = setup(&grid);

	if (ret == 0)
	{
		blob_resolution = 3;
		if (grid.x > 15)
			blob_resolution = 2;
		if (grid.x <= 7)
			blob_resolution = 4;
		fprintf(stderr, "Player turn: %d\n", grid.player_turn);
		if (grid.player_turn == TURN_PLAYER_B)
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
			x = best_move(&grid, GRID_PLAYER_A, blob_resolution);

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
