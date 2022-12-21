#include<stdio.h>
#include "../include/quiz.h"

int main() {
  int score = 0;
  char *questions[10] = {"Berapa 5 + 5?....", "enam dikali enam sama dengan...."};
  char *choices[10][4] = {{"50", "10", "20", "40"}, {"1", "30", "36", "40"}};
  char keys[10] = {'b', 'c'};
  run_questions(questions, choices, keys, &score, 2);
  printf("score anda : %d\n", score);
  return 0;
}
