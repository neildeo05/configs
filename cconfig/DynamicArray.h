#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_
#include <stdlib.h>
#include <stdio.h>

typedef union {
  int32_t i32;
  int64_t i64;
} int_t;

typedef struct {
  size_t size;
  size_t capacity;
  int_t* data;
} DynamicArray;

void xalloc(DynamicArray* arr, size_t len) {
  arr->data = realloc(arr->data, len * sizeof(int_t));
  arr->capacity = len;
  arr->size = 0;
}
void print(DynamicArray* arr) {
  for(size_t i = 0; i < arr->capacity; i++) {
    printf("{i32 -> %d i64 -> %lld}\n", arr->data[i].i32, arr->data[i].i64);
  }
}

void append(DynamicArray* arr, int32_t val) {
  if (arr->size == arr->capacity) {
    xalloc(arr, arr->capacity*2);
  }
  arr->data[arr->size] = (int_t) {.i32=val};
  arr->size++;
}

DynamicArray init() {
  DynamicArray ret = (DynamicArray) {.size=0, .capacity=0, .data = NULL};
  xalloc(&ret, 3);
  return ret;

}

void kill(DynamicArray* arr) {
  free(arr->data);
  arr->size = 0;
  arr->capacity = 0;
}

#endif
