#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "sg.h"

int main(int argc, char *argv[])
{ 
  char **strWords;
  char strFile[30];
  float x;

  int i,j=0;
  int iErrCode = 0;
  int iTokSum = 1;
  int iPrev = -1;
  int iWordSlot = 0;
  int iWordsIn = 0;
  int iToken[WORDS];

  strWords = (char **) calloc (WORDS, sizeof (char *));

  if (argc < 4) {
	  printf("Use: stimgen FILE WORDS TOKENS\n");
	  exit(1);
  }
  printf("ARGS: %s %s %s\n", argv[1], argv[2], argv[3]);
  strcpy(strFile, argv[1]);
  WORDS = atoi(argv[2]);
  MAXTOKENS = atoi(argv[3]);

  /* Load Words from file */
  iErrCode = fLoadWords(strFile, strWords);

  /* Initialize EVerything */
  for (i=0; i < WORDS; i++) {
	iToken[i] = MAXTOKENS;
	printf("************* START Word: %i:%s  Num: %i ************\n", i,strWords[i], iToken[i]);
  }
  srand (time (0));

  while (iTokSum > 0) {

	iTokSum=0; iWordSlot=0; i=0; j=0;

	for (i=0;i<WORDS;i++) {
		iTokSum = iTokSum + iToken[i];
		printf("<%s:%i>\t", strWords[i], iToken[i]);
	}

	printf("Total: %i\n",iTokSum);
	x = rand()/((double)RAND_MAX + 1);

	iWordsIn = x*iTokSum+1;
	printf("Percent in: %g Words in: %i\n", x, iWordsIn);

	while (iWordsIn > 0) {
		printf("\t\t\tWI:%i WS:%i\n", iWordsIn, iWordSlot);
		iWordsIn = iWordsIn - iToken[iWordSlot];
		if (iWordsIn > 0) 
			iWordSlot++;
	}
	printf("Slot %i\n",iWordSlot);
	if ((iWordSlot <= WORDS)&&(iWordSlot != iPrev)) {
		printf("%s\n", strWords[iWordSlot]);
		iToken[iWordSlot]--;
		iPrev = iWordSlot;
	}

  }

  return 0; 
}

int fLoadWords(char *file, char **array) {

  FILE *fp;
  char string[WORDSIZE];
  char strWord[WORDSIZE];
  char *p;
  int i=0;

  fp = fopen(file, "r");

  while(fgets(string, WORDSIZE, fp) != NULL) {
	  if ((p = strchr(string, '\n')) != NULL)
		        *p = '\0';
	  strcpy(array[i], string);
	  i++;
  }
  for (i=0; i < WORDS; i++)
	printf("************* Words: %i:%s ************\n", i,array[i]);

  return 0;
}

