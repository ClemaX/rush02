#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rush02.h"

int	setup(plateau *grid)
{
	int ret;

	ret = fscanf(stdin, "%u\n%u\n%u\n%u\n%u\n%u",
		&grid->x, &grid->y,
		&grid->win_length, &grid->player_turn,
		&grid->time_gain, &grid->total_time);

	if (ret == 6)
	{
		grid->tab = malloc(sizeof(*grid->tab) * (grid->y * grid->x + 1));
		memset(grid->tab, GRID_EMPTY, sizeof(*grid->tab) * grid->y * grid->x);
		grid->tab[grid->y * grid->x] = '\0';
		ret = -(grid->tab == NULL);
	}
	else
	{
		error("Invalid input!\n");
		ret = 1;
	}

	return ret;
}
