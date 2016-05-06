#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{ 
  float x;

  int COUNT = 0;
  int RANGE = 0;
  int i, iNum = 0;

  if (argc < 3) {
	  printf("Use: rando RANGE COUNT\n");
	  exit(1);
  }
  printf("ARGS: %s %s\n", argv[1], argv[2]);
  RANGE = atoi(argv[1]);
  COUNT = atoi(argv[2]);

  srand (time (0));

  for (i=0; i<COUNT; i++) {
	x = rand()/((double)RAND_MAX + 1);
	iNum = 2+(x*RANGE+1);
	printf("x: %f, N: %i\n", x, iNum);
  }
  return 0;
}
