#include <stdio.h>

#include "rush02.h"

#include <unistd.h>

#include <unistd.h>

int	recv_pos(int *x)
{
	int		ret = 1;

	debug("Waiting for position...\n");

	ret = fscanf(stdin, "%u", x);
	debug("Received position %d...\n", *x);
	ret = ret != 1;

	if (ret != 0)
		error("Invalid position!\n");
	return ret;
}

int	send_pos(int x)
{
	debug("Sending %u...\n", x);

	fprintf(stdout, "%u\n", x);
	fflush(stdout);

	return 0;
}
