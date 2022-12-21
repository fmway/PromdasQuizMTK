#include "../include/pages.h"
#include "../include/account.h"
#include "../include/quiz.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define BACK -1
#define LOGOUT -99

void clear(void) {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif /* _WIN32 */
}

int logout(void) {
  char input[100];
  printf("-------------------------------------------------------------\n");
  printf("k. Kembali\n");
  printf("l. Logout\n");
  printf("-------------------------------------------------------------\n");

  while(
    printf("=> "), scanf(" %[^\n]s", input),
    strcmp(input, "k") && strcmp(input, "l")
  ) printf("Opsi %s tidak ditemukan!!\n", input);

  if(!strcmp(input, "k")) {
    return BACK;
  } else {
    return LOGOUT;
  }
} 

int start(char (*username_admins)[100], char (*name_admins)[100], char (*password_admins)[100], int *len_admins, char (*username_users)[100], char (*name_users)[100], char (*password_users)[100], int *len_users, char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level) {
  int input, id, is_admin = 0, result;
  char tmp[100];
  clear();
  printf("-------------------------HOMEPAGE-----------------------\n");
  printf("1. Admin\n");
  printf("2. User\n");
  printf("--------------------------------------------------------\n");
  
  while(
    printf("=> "), scanf(" %[^\n]s", tmp), input = atoi(tmp),
    input != 1 && input != 2
  ) printf("Pilihan anda kurang tepat!!\n");
  if(input == 1) {
    is_admin = 1;
  }

back:
  clear();
  printf("------------------------%s---------------------------\n", is_admin ? "-ADMIN" : "-USER-");
  printf("1. Register\n");
  printf("2. Login\n");
  printf("---------------------------------------------------------\n");
  printf("k. Kembali\n");
  printf("l. Logout\n");
  printf("---------------------------------------------------------\n");
  while(
    printf("=> "), scanf(" %[^\n]s", tmp), input = atoi(tmp),
    input != 1 && input != 2 && strcmp(tmp, "k") && strcmp(tmp, "l")
  ) printf("Pilihan anda kurang tepat!!\n");

  if(!strcmp(tmp, "k")) {
    return start(username_admins, name_admins, password_admins, len_admins, username_users, name_users, password_users, len_users, questions, choices, keys, scores, time_plays, level);
  } else if(!strcmp(tmp, "l")) {
    return LOGOUT;
  }

if(input == 1) {
    if(is_admin) {
      id = reg(username_admins, name_admins, password_admins, len_admins);
    } else {
      id = reg(username_users, name_users, password_users, len_users);
    }
  } else {
    if(is_admin) {
      while(
        id = login(username_admins, password_admins, len_admins),
        id < 0
      ) printf("Username tidak ditemukan! Coba lagi\n");
    } else {
      while (
        id = login(username_users, password_users, len_users),
        id < 0
      ) printf("Username tidak ditemukan! Coba lagi\n");
    }
  }

  if(is_admin) {
    result = menu_admin(username_users, name_users, len_users, questions, choices, keys, scores, time_plays, level);
  } else {
    result = menu_user(username_users, name_users, len_users, questions, choices, keys, scores, time_plays, level, id);
  }

  if(result == BACK) {
    goto back;
  } else {
    return result;
  }
}

int menu_admin(char (*usernames)[100], char (*names)[100], int *len_user, char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level) {
  clear();
  int input, result;
  char tmp[100];
  printf("------------------------DASHBOARD------------------------\n");
  printf("1. Update Soal dan Kunci Jawaban\n");
  printf("2. Daftar Soal dan Kunci Jawaban\n");
  printf("3. Daftar Pemain\n");
  printf("k. Kembali\n");
  printf("l. Logout\n");
  printf("---------------------------------------------------------\n");
  while(
    printf("=> "), scanf(" %[^\n]s", tmp), input = atoi(tmp),
    strcmp(tmp, "k") && strcmp(tmp, "l") && (input < 1 || input > 3)
  ) printf("Pilihan anda tidak tepat!!\n");

  if(!strcmp(tmp, "k")) {
    return BACK;
  } else if(!strcmp(tmp, "l")) {
    return LOGOUT;
  }

  if(input == 1) {
    result = update_question(questions, choices, keys, scores, time_plays, level);
  } else if(input == 2) {
    result = get_question(questions, choices, keys, level);
  } else {
    result = get_data(usernames, names, len_user, scores, time_plays, level);
  }

  if(result == BACK) {
    return menu_admin(usernames, names, len_user, questions, choices, keys, scores, time_plays, level);
  } else {
    return result;
  }
}

int menu_user(char (*usernames)[100], char (*names)[100], int *len_user, char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[3], int (*time_plays)[3], const int level, const int id_user) {
  clear();
  int result;
  char input[100];
  printf("-----------------------DASHBOARD------------------------\n");
  printf("m. Mulai\n");
  printf("k. Kembali\n");
  printf("l. Logout\n");
  printf("--------------------------------------------------------\n");
  while(
    printf("=> "), scanf(" %[^\n]s", input),
    strcmp(input, "m") && strcmp(input, "k") && strcmp(input, "l")
  ) printf("Pilihan anda tidak tepat!!\n");

  if(!strcmp(input, "k")) {
    return BACK;
  } else if(!strcmp(input, "l")) {
    return LOGOUT;
  } else {
    level_questions(questions, choices, keys, scores[id_user], time_plays[id_user], level);
    print_score(names[id_user], usernames[id_user], scores[id_user], time_plays[id_user], level);
    result = logout();
  }
  
  if(result == BACK) {
    return menu_user(usernames, names, len_user, questions, choices, keys, scores, time_plays, level, id_user);
  } else {
    return result;
  }
}

