#ifndef GC_H_
#define GC_H_

struct Junk {
  void* junk;
  char addr[32];
};

/**
  char buff[32];
  int a = 10;
  int b = 13;
  int* s = &a;
  snprintf(buff, sizeof(buff) * sizeof(char), "%p", s);
  printf("%s\n", buff);
  s = &b;
  snprintf(buff, sizeof(buff) * sizeof(char), "%p", s);
  printf("%s\n", buff);
 */

//Junk cause it is going to be thrown away 
struct Collector {
  //the collection of junk to be garbaged out
  Junk* junk;
  //the collector pointer (ip or pc)
  int cp;
  //flag for memory leaks (when freeing/allocating/checking, if ptr is NULL, memory leak has occurred oops fprintf && exit(1)
  int cap;
  int memory_leak;
};

struct Collector new_collector();
void* xalloc(struct Collector* c, size_t size);
void xfree (struct Collector* c);


#endif


