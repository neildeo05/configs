#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gc.h"

struct tmp {
  int a;
  char string[32];
};

int main() {
  struct tmp a;
  int b = 13;
  int* s = &b;
  snprintf(a.string, sizeof(a.string) * sizeof(char), "%p", s);
  printf("%s\n", a.string);
  /*s = &b;*/
  /*snprintf(buff, sizeof(buff) * sizeof(char), "%p", s);*/
  /*printf("%s\n", buff);*/
  /*printf("%s\n", a.string);*/

  /*struct Collector c = new_collector();*/
  /*void* a = xalloc(&c, 10 * sizeof(int));*/
  /*printf("%d\n", c.cap);*/
  /*void* b = xalloc(&c, 10 * sizeof(int));*/
  /*printf("%d\n", c.cap);*/
  /*xfree(&c);*/

}
