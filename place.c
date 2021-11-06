#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GRID_EMPTY ' '
#define GRID_PLAYER_A 'X'
#define GRID_PLAYER_B 'O'

typedef struct  grille
{
    char        *data;
    unsigned    x;
    unsigned    y;
}               grille;

int    place(grille *grid, unsigned x, char player)
{
    unsigned y;
    int      pos;

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

void    print_grid(grille *grid)
{
    for (int y = grid->y - 1; y >= 0; y--)
        fprintf(stderr, "%.*s|\n", grid->x, grid->data + grid->x * y);
}

int     init_grid(grille *grid, unsigned x, unsigned y)
{
    int ret;

    grid->data = malloc(sizeof(*grid->data) * y * x);
    memset(grid->data, GRID_EMPTY, sizeof(*grid->data) * y * x);

    ret = -(grid->data == NULL);

    if (ret == 0)
    {
        
        grid->x = x;
        grid->y = y;
    }
    return ret;
}

void    clear_grid(grille *grid)
{
    free(grid->data);
    bzero(grid, sizeof(*grid));
}



int main(void)
{
    grille  grid;

    init_grid(&grid, 14, 6);

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
