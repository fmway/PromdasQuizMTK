#include "../include/mytime.h"
#include <time.h>
#include <stdlib.h>

/* "mytime.h" */
Time gettimenow(void) {
  time_t times = time((time_t*)0);
  struct tm *ttmm = localtime(&times);
  Time result = {
    .hours = ttmm->tm_hour,
    .minutes = ttmm->tm_min,
    .seconds = ttmm->tm_sec,
  };
  return result;
}

Time diftime(Time time_1, Time time_2) {
  Time result = {
    .hours = abs(time_1.hours - time_2.hours),
    .minutes = abs(time_1.minutes - time_2.minutes),
    .seconds = abs(time_1.seconds - time_2.seconds),
  };
  return result;
}

int toseconds(Time time) {
  return time.hours * 3600 + time.minutes * 60 + time.seconds;
}
