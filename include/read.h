#ifndef MY_READ_H_
#define MY_READ_H_

/* getch function is not available in other system except windows*/
#ifndef _WIN32
int getch(void);
#endif //_WIN32

/* Read input but only show asterisk */
void getpasswd(const char * prompt, char * dest);

/* Read input with multiple line */
void read_line(char * dest);

void getsv(char * dest);

#endif // !MY_READ_H_
