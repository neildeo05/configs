#ifndef SCANNER_H_
#define SCANNER_H_



#define CHECK_POINTER(ptr) \
  if(ptr == NULL) { \
    fprintf(stderr, "Pointer is null");  \
    exit(1); \
  }   \

char* BufferRead(char* src) {
  char* buffer;
  FILE *f = fopen(src, "rb");
  CHECK_POINTER(f);
  fseek(f, 0, SEEK_END);
// Take into account last line of data
  size_t size = ftell(f) - 1;
  fseek(f, 0, SEEK_SET);
  buffer = malloc(size * sizeof(char));
  CHECK_POINTER(buffer);
  fread(buffer, 1, size, f);
  fclose(f);
  return buffer;
}
typedef struct {
  long* dat;
  int len;
} Result;

Result ArrayRead(char* src) {
  FILE *f = fopen(src, "rb");
  CHECK_POINTER(f);
  fseek(f, 0, SEEK_END);
  size_t size = ftell(f) - 1;
  fseek(f, 0, SEEK_SET);
  long* data = malloc(size * sizeof(long));
  CHECK_POINTER(data);
  int base = 0;
  while(!feof(f)) {
    long x = 0;
    fscanf(f, "%ld", &x);
    data[base] = x;
    base++;
  }
  fclose(f);
  return (Result) {.dat=data, .len=base-1};

}

#endif
