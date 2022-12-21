#include <stdio.h>
#include "../include/read.h"

int main() {
  char password[100];
  getpasswd("Masukkan Password: ", password);
  printf("%s\n", password);
}
