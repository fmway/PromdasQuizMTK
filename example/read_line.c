#include<stdio.h>
#include<stdlib.h>
#include "../include/read.h"

int main() {
  char input[1000];
  printf("Tekan Escape lalu enter untuk keluar dari sini!\n");
  read_line(input);
  system("clear");
  printf("%s\n", input);
  return 0;
}
