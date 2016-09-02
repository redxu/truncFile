

#include <stdio.h>
#include "trunc.h"


int main(int argc, char** argv)
{
	int rtv = truncFile("./test.bin");
	printf("truncFile turn: %d\n", rtv);
	return rtv;
}
