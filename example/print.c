#include<stdio.h>
#include "../include/quiz.h"

int main() {
  char *questions[2][10] = {
    {"Berapa 5 + 5?....", "enam dikali enam sama dengan...."},
    {"6 * 5 = ...", "10 * 10 = ...."},
  };

  char *choices[2][10][4] = {
    {{"50", "10", "20", "40"}, {"1", "30", "36", "40"}},
    {{"15", "30", "25", "40"}, {"10", "1", "1000", "100"}},
  };
  char keys[2][10] = {
    {'b', 'c'},
    {'b', 'd'},
  };

  printf("Pertanyaan :\n");
  for(int i = 0; i < 2; i ++) {
    printf("Level %d:\n", i + 1);
    print_questions(questions[i], 2);
  }
  printf("------------------------------\n");
  printf("Pilihan ganda:\n");
  for(int i = 0; i < 2; i ++) {
    printf("--------\nLevel %d:\n", i + 1);
    for(int j = 0; j < 2; j ++) {
      printf("-------\nNo. %d\n", j + 1);
      print_choices(choices[i][j], 2);
    }
  }
  
  printf("-------------------------------\n");
  printf("Kunci Jawaban:\n");
  for(int i = 0; i < 2; i ++) {
    printf("Level %d:\n", i + 1);
    print_keys(keys[i], 2);
  }

  return 0;
}
