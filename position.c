#include <stdio.h>

#include "rush02.h"

#include <unistd.h>

#include <unistd.h>

int		recv_pos(int *x)
{
	int		ret = 1;


	fprintf(stderr, "Waiting for position...\n");

	ret = fscanf(stdin, "%u", x);
	fprintf(stderr, "Received position %d...\n", *x);
	ret = ret != 1;

	if (ret != 0)
		fprintf(stderr, "Invalid position!\n");
	return ret;
}

int		send_pos(int x)
{
	fprintf(stderr, "Sending %u...\n", x);

	fprintf(stdout, "%u\n", x);

	fflush(stdout);
	return 0;
}
