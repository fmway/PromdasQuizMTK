#include "../include/quiz.h"
#include "../include/pages.h"
#include "../include/mytime.h"
#include "../include/read.h"
#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#define BACK -1
#define LOGOUT -99

void run_questions(char **questions, char *(*choices)[4], char *keys, int *score, const int len_questions)
 {
  for(int i = 0; i < len_questions ; i++) {
    if(keys[i]) {
      char input;
      printf("--------------------------------------------------------------------\n");
      printf("| No. %-2d |\n", i + 1);
      printf("----------\n");
      printf("%s\n", questions[i]);
      for(int j = 0; j < 4; j++) {
        printf("%c. %s\n", (char)(j + 97), choices[i][j]);
      }
      printf("--------------------------------------------------------------------\n");
      while (
        printf("=> "), scanf(" %c", &input),
        input = tolower(input),
        input < 97 || input > 100 ) printf("Pilihan anda tidak sesuai!!\n");
      if(input == tolower(keys[i])) (*score)++;
    }
  }
}

void level_questions(char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int * scores, int * time_plays, const int level) {
  for(int i = 0; i < level ; i++) {
    Time time = gettimenow();
    int score = 0;
    if(keys[i][0]) {
      clear();
      printf("=Level %d============================================================\n", i + 1);
      run_questions(questions[i], choices[i], keys[i], &score, 10);
      scores[i] = score;
      time_plays[i] = toseconds(diftime(gettimenow(), time));
      if(score < 10) break;
    }
  }
}

void print_questions(char **questions, const int len_questions) {
  for(int i = 0; i < len_questions; i++) {
    if(questions[i])
      printf("%d. %s\n", i + 1, questions[i]);
  }
}

void print_choices(char **choices, const int len_choices) {
  for(int i = 0; i < len_choices ; i++) {
    if(choices[i][0])
      printf("%c. %s\n", (char)(i + 97), choices[i]);
  }
}

void print_keys(char *keys, const int len_keys) {
  for(int i = 0; i < len_keys ; i++)
    if(keys[i])
      printf("%d. %c\n", i + 1, keys[i]);
}

void print_score(char *name, char *username, int *score, int *time_plays, const int level) {
  printf("-------------------------------------------------------------\n");
  printf("| Nama     : %-46s |\n", name);
  printf("| Username : %-46s |\n", username);
  printf("| Skor:                                                     |\n");
  for(int i = 0; i < level; i++) {
    printf("| - Level %d: %-2d poin, %3d detik                             |\n", i + 1, score[i], time_plays[i]);
  }
  printf("-------------------------------------------------------------\n");
}

int update_question(char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], int (*scores)[], int (*time_plays)[], const int level) {
  int types, input, num, result;
  char tmp[100];
  clear();
  printf("---------------------------------------------------------\n");
  printf("1. Edit Soal\n");
  printf("2. Kunci Jawaban\n");
  printf("---------------------------------------------------------\n");
  printf("k. Kembali\n");
  printf("l. Logout\n");
  printf("---------------------------------------------------------\n");
  while(
    printf("=> "), scanf(" %[^\n]s", tmp), types = atoi(tmp),
    strcmp(tmp, "k") && strcmp(tmp, "l") && types != 1 && types != 2
  ) printf("Pilihan anda tidak tepat!\n");

  if(!strcmp(tmp, "l")) {
    return LOGOUT;
  } else if(!strcmp(tmp, "k")) {
    return BACK;
  }
back:
  clear();
  printf("---------------------------------------------------------\n");
  for(int i = 1; i <= level; i++)
    printf("%d. Level %d\n", i, i);
  printf("---------------------------------------------------------\n");
  printf("k. Kembali\n");
  printf("l. Logout\n");
  printf("---------------------------------------------------------\n");
  while(
    printf("=> "), scanf(" %s", tmp), input = atoi(tmp),
    strcmp(tmp, "k") && strcmp(tmp, "l") && (input < 1 || input > level)
  ) printf("Pilihan anda tidak tepat!\n");

  if(!strcmp(tmp, "l")) {
    return LOGOUT;
  } else if(!strcmp(tmp, "k")) {
    return update_question(questions, choices, keys, scores, time_plays, level);
  }
  
  clear();
  printf("==========================Level %d============================\n", input);
  if(types == 1) {
    char input3[100];
    print_questions(questions[input-1], 10);
    printf("---------------------------------------------------------\n");
    printf("k. Kembali\n");
    printf("l. Logout\n");
    printf("---------------------------------------------------------\n");

    while(
      printf("=> "), scanf(" %[^\n]s", tmp), num = atoi(tmp),
      (num < 1 || num > 10) && strcmp(tmp, "k") && strcmp(tmp, "l")
    ) printf("Pilih dari Nomor 1 hingga 10! atau k untuk kembali dan l untuk logout\n");
    
    if(!strcmp(tmp, "l")) {
      return LOGOUT;
    } else if(!strcmp(tmp, "k")) {
      goto back;
    }

    while(true) {
      clear();
      char yn;
      while(
        printf("%s\n", questions[input-1][num]),
        printf("Edit? (y/n)\n=> "), scanf(" %c", &yn),
        tolower(yn) != 'y' && tolower(yn) != 'n'
      ) printf("Pilihan anda salah\n");

      if(tolower(yn) == 'y') {
        clear();
      } else {
        break;
      }

      printf("%s\n", questions[input-1][num]);
      printf("--------------------------------------------------------------\n");
      printf("Tekan Escape lalu enter untuk save dan keluar!\n");
      printf("--------------------------------------------------------------\n");
      questions[input-1][num] = (char *)(malloc(500 * sizeof(char)));
      read_line(questions[input-1][num]);
      questions[input-1][num][0] = ' ';
      clear();
      printf("%s\n", questions[input-1][num]);
      while(
        printf("Apakah sudah benar ? (y/n)\n=> "), scanf(" %[^\n]s", input3),
        strcmp(input3, "y") && strcmp(input3, "Y") && strcmp(input3, "n") && strcmp(input3, "N")
      ) printf("Pilihan anda kurang tepat");
      if(!strcmp(input3, "Y") || !strcmp(input3, "y")) break; 
    }
    while(true) {
      clear();
      print_choices(choices[input-1][num], 4);
      while(
        printf("Edit? (y/n) => "), scanf(" %[^\n]s", input3),
        strcmp(input3, "Y") && strcmp(input3, "y") && strcmp(input3, "n") && strcmp(input3, "N")
      ) printf("Pilihan anda kurang tepat!\n");

      if(!strcmp(input3, "Y") || !strcmp(input3, "y")) {
        char input4;
        while(
          printf("Pilih yang ingin di edit [a-d]\n=> "), scanf(" %c", &input4),
          input4 < 'a' || input4 > 'd'
        ) printf("Anda salah memasukkan pilihan!\n");
        printf("[%s] => ", choices[input-1][num][input4-97]);
        choices[input-1][num][input4-97] = (char *)(malloc(100 * sizeof(char)));
        scanf(" %[^\n]s", choices[input-1][num][input4-97]);
      } else {
        goto back;
      }
    }
  } else {
    int input2;
    while(true) {
      char ch;
      print_keys(keys[input-1], 10);
      printf("---------------------------------------------------------\n");
      printf("k. Kembali\n");
      printf("l. Logout\n");
      printf("---------------------------------------------------------\n");

      while(
        printf("=> "), scanf(" %[^\n]s", tmp), input2 = atoi(tmp),
        (input2 < 1 || input2 > 10) && strcmp(tmp, "k") && strcmp(tmp, "l")
      ) printf("Pilihan anda salah!\n");

      if(!strcmp(tmp, "l")) {
        return LOGOUT;
      } else if(!strcmp(tmp, "k")) {
        goto back;
      }
      while(
        printf("[a-d] => "), scanf(" %c", &ch), ch = tolower(ch),
        ch < 'a' || ch > 'd'
      ) printf("Anda salah Memasukkan Jawaban!\n");
      keys[input-1][input2-1] = ch;
   }
  }
}

int get_question(char *(*questions)[10], char *(*choices)[10][4], char (*keys)[10], const int level) {
  int input, types, result;
  char tmp[100];
  clear();
  printf("---------------------------------------------------------\n");
  printf("1. Daftar Soal\n");
  printf("2. Daftar Pilihan Ganda\n");
  printf("3. Kunci Jawaban\n");
  printf("---------------------------------------------------------\n");
  printf("k. Kembali\n");
  printf("l. Logout\n");
  printf("---------------------------------------------------------\n");
  while(
    printf("=> "), scanf(" %[^\n]s", tmp), types = atoi(tmp),
    (types < 1 || types > 3) && strcmp(tmp, "k") && strcmp(tmp, "l")
  ) printf("Pilihan anda tidak tepat!\n");

  if(!strcmp(tmp, "l")) {
    return LOGOUT;
  } else if(!strcmp(tmp, "k")) {
    return BACK;
  }

back:
  clear();
  printf("---------------------------------------------------------\n");
  for(int i = 1; i <= level; i++)
    printf("%d. Level %d\n", i, i);
  printf("---------------------------------------------------------\n");
  printf("k. Kembali\n");
  printf("l. Logout\n");
  printf("---------------------------------------------------------\n");
  while(
    printf("=> "), scanf(" %s", tmp), input = atoi(tmp),
    strcmp(tmp, "k") && strcmp(tmp, "l") && (input < 1 || input > level)
  ) printf("Pilihan anda tidak tepat!\n");

  if(!strcmp(tmp, "l")) {
    return LOGOUT;
  } else if(!strcmp(tmp, "k")) {
    return get_question(questions, choices, keys, level);
  }

  clear();
  printf("==========================Level %d============================\n", input);
  if(types == 1) {
    print_questions(questions[input - 1], 10);
  } else if(types == 2) {
    for(int i = 0; i < 10; i ++) {
      printf("-------------------------------------------------------------\n");
      printf("| No. %-2d |\n", i + 1);
      printf("----------\n");
      print_choices(choices[input - 1][i], 4);
      printf("-------------------------------------------------------------\n");
    }
  } else {
    print_keys(keys[input - 1], 10);
  }
  printf("-------------------------------------------------------------\n");
  result = logout();

  if(result == BACK) {
    goto back;
  } else {
    return result;
  }
}

int get_data(char (*usernames)[100], char (*names)[100], int *len_user, int (*scores)[3], int (*time_plays)[3], const int level) {
  clear();
  for(int i = 0; i < *len_user; i++) 
    print_score(names[i], usernames[i], scores[i], time_plays[i], level);
  return logout();
}
