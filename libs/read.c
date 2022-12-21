#include "../include/read.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* "read.h" */
#ifndef _WIN32
#include<unistd.h>
#include<termios.h>

int getch(void) {
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}

#endif /* _WIN32 */


void getpasswd(const char * prompt, char * dest) {
  char pass[100];
  int i = 0;
  char tmp = ' ';
  printf("%s", prompt);
  while(true) {
    if(i != 0 && (tmp == '\n' || tmp == (char)10 || tmp == (char)12 || tmp == (char)13)) break;
    tmp = getch();
    if(tmp != 127 && tmp > 31) {
      printf("*");
      pass[i] = tmp;
      i++;
    } else if(i !=0 && (tmp == '\b' || tmp == (char)127)) {
      int len = strlen(prompt) + i;
      for(int j = 0; j < len; j++) printf("\r");
      for(int j = 0; j < len; j++) printf(" ");
      for(int j = 0; j < len; j++) printf("\r");
      printf("%s", prompt);
      for(int j = 0; j<i-1; j++) printf("*");
      pass[i] = '\0';
      i--;
    }
  }
  printf("\n");
  pass[i] = '\0';
  strcpy(dest, pass);
}

void read_line(char * dest) {
  char c;
  int index = 0;
  dest[index] = '\0';
  while(c = getchar(), c != (char)27) {
    dest[index++] = c;
  }
  dest[index] = '\0';
  printf("\n");
}

void getsv(char * dest) {
  int len = strlen(dest);
  char tmp = ' ';
  printf("%s", dest);
  while(tmp = getch(), tmp != '\n' && tmp != (char)13) {
    if(tmp == '\b' || tmp == (char)127) {
      for(int j = 0; j < len + 1; j++) printf("\r");
      for(int j = 0; j < len + 1; j++) printf(" ");
      for(int j = 0; j < len + 1; j++) printf("\r");
      dest[--len] = '\0';
      printf("%s", dest);
    } else {
      printf("%c", tmp);
      dest[len++] = tmp;
    }
  }
  //printf("\n");
}
