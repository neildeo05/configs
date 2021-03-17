#include "DynamicArray.h"
#include "Scanner.h"

int main() {
  Result text = ArrayRead("data.txt");
  for(int i = 0; i < text.len; i++) {
    printf("%ld\n", text.dat[i]);
  }
  free(text.dat);
  DynamicArray arr = init();
  append(&arr, 10);
  append(&arr, 10);
  append(&arr, 10);
  append(&arr, 10);
  print(&arr);
  kill(&arr);
}
