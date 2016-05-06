static int MAXB = 1000;
int WORDS = 16;
int MAXTOKENS = 100;
int WORDSIZE = 12;
int SEGMENTS = 20; /* Number of gradations for each vowel frequency */
int VOWELS = 3; /* Number of initial vowels in the system */
int COMBOS = 5; /* Number of toekn exchanges during each cycle */

int fLoadWords(char *file, char **array);
