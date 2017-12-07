#include "gfx.h"
#include "enemyship.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <vector>
using namespace std;
void createShip(int, int, int);
void moveShot();
vector <int> xshots;
vector <int> yshots;

int main() {
  srand(time(NULL));
  gfx_open(510, 680, "Galaga");
  //Enemy en;
  int x = 255, y = 664, rad0 = 5, rad1 = 15, y1 = 664;

  char c= 0;
  while (c != 'q') {
    c = 0;
    gfx_flush();
    usleep(5000);
    createShip(x, y, rad1);
    if (gfx_event_waiting()) {
      c = gfx_wait();
      if (c == 'q')
        return 0;
      else if(c == 's'){
        gfx_circle(x, y1 - rad1 - rad0, rad0);
        xshots.push_back(x);
        yshots.push_back(y1 - rad1 - rad0);
      }
      else if(c == 'S'){
        if(x > 495){
          x = 495;
        }
        else{
          x += 5;
        }
      }
      else if(c == 'Q'){
        if(x < 15){
          x = 15;
        }
        else{
          x -= 5;
        }
      }
    }
    gfx_clear();
    moveShot();
    //en.play();
  }
  return 0;
}

void createShip(int x, int y, int rad){
  gfx_line(x - rad, y, x + rad, y);
  gfx_line(x + rad, y, x, y - rad);
  gfx_line(x, y - rad, x - rad, y);
}

void moveShot(){
  if(xshots.size() > 0){
    for(int i = 0; i < xshots.size(); i++){
      yshots[i] -= 5;
      gfx_circle(xshots[i], yshots[i], 5);
    }
  }
}

