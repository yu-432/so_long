#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
  FILE *fp;

  fp = fopen("nonexistent_file.txt", "r");
  if (fp == NULL) {
    int errnum = errno;
    char *errstr = strerror(errnum);
    printf("Error opening file: %s\n", errstr);
  } else {
    printf("File opened successfully.\n");
    fclose(fp);
  }

  return 0;
}
