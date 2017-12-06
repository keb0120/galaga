// main driver
#include "gfx.h"
#include "enemyship.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

using namespace std;
int main() {
  srand(time(NULL));
  gfx_open(510, 680, "Galaga");
  Enemy en;
  
  
  char c= 0;
  while (c != 'q') {
    if (gfx_event_waiting()) {
      c = gfx_wait();
      if (c == 'q')
	return 0;
    }
    en.play();
    usleep(2000000);
  }
  return 0;
}
