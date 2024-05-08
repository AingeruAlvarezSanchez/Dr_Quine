#include <stdio.h>
#define SOURCE_CODE "#include <stdio.h>%1$c#define SOURCE_CODE %2$c%3$s%2$c%1$c#define PROGRAM() int main(){ %4$c%1$c  FILE *file = fopen(%2$cGrace_kid.c%2$c, %2$cw%2$c); %4$c%1$c  fprintf(file, SOURCE_CODE, 10, 34, SOURCE_CODE, 92); %4$c%1$c  fclose(file); %4$c%1$c  return 0; %4$c%1$c  }%1$c%1$c/*%1$c  This program aims to demonstrate how%1$c  to write a quine (self replicating program)%1$c  using only define macros and file manipulation%1$c  functions to write its own code into another%1$c  file.%1$c*/%1$cPROGRAM()%1$c"
#define PROGRAM() int main(){ \
  FILE *file = fopen("Grace_kid.c", "w"); \
  fprintf(file, SOURCE_CODE, 10, 34, SOURCE_CODE, 92); \
  fclose(file); \
  return 0; \
  }

/*
  This program aims to demonstrate how
  to write a quine (self replicating program)
  using only define macros and file manipulation
  functions to write its own code into another
  file.
*/
PROGRAM()
