#include "../include/account.h"

#include<stdio.h>

int main() {
  char names[100][100] = {"Users"};
  char usernames[100][100] = {"users"};
  char passwords[100][100] = {"users"};
  int len_users = 1;

  char pilih;
  int id;
  while(
    printf("1. Login\n"),
    printf("2. Register\n"),
    printf("k. keluar\n"),
    printf("=> "),
    scanf(" %c", &pilih),
    pilih != 'k' 
  ) {
      if(pilih == '1') {
        while(1) {
          id = login(usernames,passwords,&len_users);
          if(id < 0) {
            printf("User tidak ditemukan!!\n");
          } else {
            break;
          }
        }
      }
      else if(pilih == '2') {
        id = reg(usernames, names, passwords, &len_users);
      }
      else {
        printf("Anda salah memasukkan pilihan!\n");
        continue;
      }
      printf("id : %d\n", id);
      for(int i = 0; i < len_users; i++) {
        printf("---------------------------------------\n");
        printf("Nama     : %s\n", names[i]);
        printf("Username : %s\n", usernames[i]);
        printf("Password : %s\n", passwords[i]);
        printf("---------------------------------------\n");
      }
    }

  return 0;
}
