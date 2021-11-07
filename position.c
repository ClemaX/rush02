#include <stdio.h>

#include "rush02.h"

int		recv_pos(int *x)
{
	int	ret;

	fprintf(stderr, "Waiting for position...\n");

	ret = fscanf(stdin, "%u", x);
	ret = ret != 1;

	if (ret != 0)
		fprintf(stderr, "Invalid position!\n");
	return ret;
}

int		send_pos(int x)
{
	return fprintf(stdout, "%u\n", x) == -1;
}
