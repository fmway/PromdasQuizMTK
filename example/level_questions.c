#include<stdio.h>
#include "../include/quiz.h"

int main() {
  int scores[] = {0, 0};
  int times[] = {0, 0};
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
  level_questions(questions, choices, keys, scores, times, 2);
  for(int i = 0; i < 2; i++) {
    printf("score %d : %d\n", i + 1, scores[i]);
    printf("time    : %d detik\n", times[i]);
  }
  return 0;
}
