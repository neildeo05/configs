#include <stdio.h>
#include <stdlib.h>
#include "gc.h"

struct Collector new_collector() {
  struct Collector ret;
  ret.cp = 0;
  ret.cap = 1;
  ret.junk = malloc(ret.cap * sizeof(Junk));
  ret.memory_leak = 0;
  return ret;
}

void* xalloc(struct Collector* c, size_t size) {
  if(c->cp >= c->cap) {
    c->cap *= 2;
    c->junk = realloc(c->junk, c->cap);
  }
  void* ptr = malloc(size);
  c->junk->junk[c->cp] = ptr;
  c->cp++;
  return ptr;
}


void xfree(struct Collector* c) {
  for (int i = 0; i < c->cp; i++) {
    void* curr = c->junk[i];
    if(curr == NULL) {
      fprintf(stderr, "ERROR: Trying to free pointer %p has not been allocated", curr);
      exit(1);
    }
    printf("freeing %p\n", curr);
    free(curr);
  }
  printf("freeing collector %p\n", c->junk);
  free(c->junk);
}

