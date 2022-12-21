#include "../include/account.h"
#include "../include/read.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int login(char (*usernames)[100], char (*passwords)[100], int *len_user) {
  char username[100], password[100];
  int pass = -1;
  printf("Username : "); scanf(" %[^\n]s", username);
  for(int i = 0; i < *len_user; i++) {
    if(!strcmp(username, usernames[i])) pass = i;
  }
  if(pass >= 0) {
    while(true) {
      getpasswd("Password : ", password);
      if(!strcmp(passwords[pass], password)) {
        break;
      } else {
        printf("Password Salah!! Coba lagi!!!\n");
      }
    }
  }
  return pass;
}

int reg(char (*usernames)[100], char (*names)[100], char (*passwords)[100], int *len_user) {
  char username[100], name[100];
  printf("Nama : "); scanf(" %[^\n]s", name); strcpy(names[*len_user], name);
  while(true) {
    bool pass = false;
    printf("Username : "); scanf(" %[^\n]s", username);
    for(int i = 0; i < *len_user; i++)
      if(!strcmp(usernames[i], username)) pass = true;
    if(pass) {
      printf("Username sudah digunakan! Coba yang lain!!\n");
    } else {
      strcpy(usernames[*len_user], username);
      break;
    }
  }
  getpasswd("Password : ", passwords[*len_user]);
  return (*len_user)++;
}
