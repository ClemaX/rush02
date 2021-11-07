#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rush02.h"

int		place(plateau *grid, int x, char player)
{
	int	y;
	int	pos;

	for (y = 0; y < grid->y && grid->tab[grid->x * y + x] != GRID_EMPTY; y++)
		;

	if (y < grid->y)
	{
		pos = grid->x * y + x;
		grid->tab[pos] = player;
		//fprintf(stderr, "Placed %c at %u %u!\n", player, x, y);
	}
	else
		pos = -1;

	return -1;
}

void	print_grid(plateau *grid)
{
	fprintf(stderr, "Grid width: %u, height: %u, win-length: %u\n",
		grid->x, grid->y, grid->win_length);

	for (int y = grid->y - 1; y >= 0; y--)
		fprintf(stderr, "%.*s|\n", grid->x, grid->tab + grid->x * y);
}

void	clear_grid(plateau *grid)
{
	free(grid->tab);
	bzero(grid, sizeof(*grid));
}
