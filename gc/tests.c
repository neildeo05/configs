#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#include "gc.h"*/
int main() {
  /*struct Collector c = new_collector();*/
  /*void* a = xalloc(&c, 10 * sizeof(int));*/
  /*printf("%d\n", c.cap);*/
  /*void* b = xalloc(&c, 10 * sizeof(int));*/
  /*printf("%d\n", c.cap);*/
  /*xfree(&c);*/

  char buff[32];
  int a = 10;
  int b = 13;
  int* s = &a;
  snprintf(buff, sizeof(buff) * sizeof(char), "%p", s);
  printf("%s\n", buff);
  s = &b;
  snprintf(buff, sizeof(buff) * sizeof(char), "%p", s);
  printf("%s\n", buff);
}
