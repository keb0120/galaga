#include "gfx.h"
#include "enemyship.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

void createShip(int, int, int);

using namespace std;
int main() {
  srand(time(NULL));
  gfx_open(510, 680, "Galaga");
  //Enemy en;
  int x = 255, y = 664, rad = 15, y1 = 664;


  char c= 0;
  while (c != 'q') {
    c = 0;
    createShip(x, y, rad);
    if (gfx_event_waiting()) {
      c = gfx_wait();
      if (c == 'q')
        return 0;
      else if(c == 's'){
        gfx_line(x, y1 - rad, x, y1 - rad - 5);
        gfx_flush();
      }
      else if(c == 'S'){
        x += 5;
      }
      else if(c == 'Q'){
        x -= 5;
      }
    }
    cout << c << endl;
    gfx_clear();
    //en.play();
    /*if(c == 's'){
      for(int i = 0; i < 28; i++){
        gfx_clear();
        createShip(x, y, rad);
        gfx_line(x, y1 - rad, x, y1 - rad - 5);
        gfx_flush();
        usleep(715);
      }
    }*/
  }
  return 0;
}

void createShip(int x, int y, int rad){
  gfx_line(x - rad, y, x + rad, y);
  gfx_line(x + rad, y, x, y - rad);
  gfx_line(x, y - rad, x - rad, y);
}

