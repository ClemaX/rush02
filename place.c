#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GRID_EMPTY ' '
#define GRID_PLAYER_A 'X'
#define GRID_PLAYER_B 'O'

typedef struct	grille
{
	char		*data;
	unsigned	x;
	unsigned	y;
	unsigned	win_length;
	unsigned	player_b_starts;
	unsigned	total_time;
	unsigned	time_gain;
}				grille;

int	place(grille *grid, unsigned x, char player)
{
	unsigned	y;
	int			pos;

	for (y = 0; y < grid->y && grid->data[grid->x * y + x] != GRID_EMPTY; y++)
		;

	if (y < grid->y)
	{
		pos = grid->x * y + x;
		grid->data[pos] = player;
		//fprintf(stderr, "Placed %c at %u %u!\n", player, x, y);
	}
	else
		pos = -1;

	return -1;
}

void	print_grid(grille *grid)
{
	fprintf(stderr, "Grid width: %u, height: %u, win-length: %u\n",
		grid->x, grid->y, grid->win_length);

	for (int y = grid->y - 1; y >= 0; y--)
		fprintf(stderr, "%.*s|\n", grid->x, grid->data + grid->x * y);
}

void	clear_grid(grille *grid)
{
	free(grid->data);
	bzero(grid, sizeof(*grid));
}

int	setup(grille *grid)
{
	int ret;

	ret = fscanf(stdin, "%u\n%u\n%u\n%u\n%u\n%u",
		&grid->x, &grid->y,
		&grid->win_length, &grid->player_b_starts,
		&grid->time_gain, &grid->total_time);

	if (ret == 6)
	{
		grid->data = malloc(sizeof(*grid->data) * grid->y * grid->x);
		memset(grid->data, GRID_EMPTY, sizeof(*grid->data) * grid->y * grid->x);
		ret = -(grid->data == NULL);
	}
	else
	{
		fprintf(stderr, "Invalid input!\n");
		ret = 1;
	}

	return ret;
}

int main(void)
{
	grille  grid;

	setup(&grid);

	place(&grid, 0, 'X');
	place(&grid, 0, 'X');
	place(&grid, 0, 'X');
	place(&grid, 0, 'X');
	place(&grid, 0, 'X');
	place(&grid, 0, 'X');
	place(&grid, 1, 'X');

	print_grid(&grid);

	clear_grid(&grid);

	return 0;
}
