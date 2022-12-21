#ifndef MY_TIME_H_
#define MY_TIME_H_

/* Standar type of Time */
typedef struct Time {
  int hours;
  int minutes;
  int seconds;
} Time;

/* Get time now */
Time gettimenow(void);

/* Get different of two times */
Time diftime(Time time_1, Time time_2);

/* Convert from Time struct to seconds as integer */
int toseconds(Time time);

#endif // !MY_TIME_H_
