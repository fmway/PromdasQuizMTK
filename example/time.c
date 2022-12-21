#include <stdio.h>
#ifdef WIN
#include<windows.h>
#else
#include<unistd.h>
#endif /* WIN */
#include "../include/mytime.h"


int main() {
  Time time1 = gettimenow();
  printf("Sekarang jam %d:%d:%d\n", time1.hours, time1.minutes, time1.seconds);
  sleep(3);
  fflush(stdin);
  Time time2 = gettimenow();
  printf("Tapi sekarang jam %d:%d:%d\n", time2.hours, time2.minutes, time2.seconds);
  Time time3 = diftime(time1, time2);
  printf("Perbedaannya adalah %d jam %d menit %d detik\n", time3.hours, time3.minutes, time3.seconds);
  printf("Atau %d detik\n", toseconds(time3));
  return 0;
}
