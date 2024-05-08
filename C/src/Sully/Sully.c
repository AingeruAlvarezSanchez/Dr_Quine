#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SOURCE_CODE "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c#define SOURCE_CODE %2$c%3$s%2$c%1$c%1$c/*%1$c  This program aims to demonstrate how%1$c  to write a quine (self replicating program)%1$c  using only define macros and file manipulation%1$c  functions alongside system calls to write its%1$c  own code into another file, compile that file%1$c  and execute it.%1$c*/%1$cint main() {%1$c  int layer = %4$d;%1$c  if (layer <= 0) {%1$c    return 0;%1$c  }%1$c%1$c  char source_filename[10];%1$c  sprintf(source_filename, %2$cSully_%%d.c%2$c, layer);%1$c  if (strcmp(source_filename, __FILE__) == 0) {%1$c    --layer;%1$c  }%1$c  sprintf(source_filename, %2$cSully_%%d.c%2$c, layer);%1$c%1$c  FILE *source_file = fopen(source_filename, %2$cw%2$c);%1$c  fprintf(source_file, SOURCE_CODE, 10, 34, SOURCE_CODE, layer);%1$c  fclose(source_file);%1$c%1$c  char exec_filename[9];%1$c  char compile_cmd[54];%1$c  sprintf(exec_filename, %2$cSully_%%d%2$c, layer);%1$c  sprintf(compile_cmd, %2$cclang -Os -fno-stack-protector -o %%s %%s%2$c, exec_filename, source_filename);%1$c  system(compile_cmd);%1$c%1$c  char exec_cmd[11];%1$c  sprintf(exec_cmd, %2$c./%%s%2$c, exec_filename);%1$c  system(exec_cmd);%1$c%1$c  return 0;%1$c}%1$c"

/*
  This program aims to demonstrate how
  to write a quine (self replicating program)
  using only define macros and file manipulation
  functions alongside system calls to write its
  own code into another file, compile that file
  and execute it.
*/
int main() {
  int layer = 5;
  if (layer <= 0) {
    return 0;
  }

  char source_filename[10];
  sprintf(source_filename, "Sully_%d.c", layer);
  if (strcmp(source_filename, __FILE__) == 0) {
    --layer;
  }
  sprintf(source_filename, "Sully_%d.c", layer);

  FILE *source_file = fopen(source_filename, "w");
  fprintf(source_file, SOURCE_CODE, 10, 34, SOURCE_CODE, layer);
  fclose(source_file);

  char exec_filename[9];
  char compile_cmd[54];
  sprintf(exec_filename, "Sully_%d", layer);
  sprintf(compile_cmd, "clang -Os -fno-stack-protector -o %s %s", exec_filename, source_filename);
  system(compile_cmd);

  char exec_cmd[11];
  sprintf(exec_cmd, "./%s", exec_filename);
  system(exec_cmd);

  return 0;
}
