#include "PolymorphicDynamicArray.h"
#include "Scanner.h"

int main() {
  Result text = ArrayRead("data.txt");
  for(int i = 0; i < text.len; i++) {
    printf("%ld\n", text.dat[i]);
  }
  free(text.dat);
  DynamicArray arr = init(3);
  append(&arr, 10);
  append(&arr, 10);
  append(&arr, 10);
  append(&arr, 2147483648);
  print(&arr);
  printf("%d\n", get(&arr, 3).i32);
  kill(&arr);
}
