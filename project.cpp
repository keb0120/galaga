#include "gfxnew.h"
#include "enemyship.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void createShip(int, int, int);
void moveShot();
void eraseShot(Enemy, int&);
void masterpiece();
bool  menu();
void instructions();

vector <int> xshots;
vector <int> yshots;

int main() {
  srand(time(NULL));
  
 
  
  Enemy en;
  int x = 255, y = 664, rad0 = 5, rad1 = 15, y1 = 664, counter = 1001, counter2 = 0;
  int n = 1, numberHit = 0;
  bool check = false, play = false;
  char score[] = "Number of";
  char score1[] = "rounds played:";
  char numberHit1[] = "Number of";
  char numberHit2[] = "enemy ships";
  char numberHit3[] = "hit:"; 
  char c = 0;

  play = menu();

  if (play) {
     gfx_open(600, 680, "Galaga");
     gfx_clear_color(106, 66, 244);
    while (c != 'q') {
      gfx_text(510, 30, score);
      gfx_text(510, 43, score1);
      gfx_text(510, 56, (to_string(n)).c_str());
      gfx_text(510, 70, numberHit1);
      gfx_text(510, 83, numberHit2);
      gfx_text(510, 96, numberHit3);
      gfx_text(510, 110, (to_string(numberHit)).c_str());
      c = 0;
      gfx_flush();
      usleep(5000);
      en.display();
      createShip(x, y, rad1);
      if (gfx_event_waiting()) {
	c = gfx_wait();
	if (c == 'q')
	  return 0;
	else if(c == 's' && counter2 > 100){
	  gfx_circle(x, y1 - rad1 - rad0, rad0);
	  xshots.push_back(x);
	  yshots.push_back(y1 - rad1 - rad0);
	  counter2 = 0;
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
      moveShot();
      eraseShot(en, numberHit);
      check = en.lose((to_string(numberHit)).c_str(), (to_string(n)).c_str());
      if(check == true) {
	while (c != 'q') {
	c = gfx_wait();
	if (c == 'q')
	  break;
	}
      }
      
      if (counter > 500) {
	en.play();
	n++;
      counter = 0;
      }
      counter++;
      counter2++;
    }
  }
  else
    return 0;

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

void eraseShot(Enemy en, int & numberHit){
  bool check = false;
  for(int i = 0; i < xshots.size(); i++){
    check = en.collision(xshots[i], yshots[i], 5);
    if(check == true){
      xshots.erase(xshots.begin() + i);
      yshots.erase(yshots.begin() + i);
      numberHit++;
    }
  }
}

void masterpiece() {
  // ASCII art it's beautiful
  cout << "                                            ```..----------...``            ``                      " << endl
       << "                                    ``.:/++oosssssssssssssssssssso+//-.`` ``                        " << endl
       << "                               `.:/oossssyysssooo+////:::////++oooossssso++:.`               `..-.` " << endl
       << "                          `.-/ossssyssoo/:---:/:`                ``..-+s+osssso/-.      `-/+ossssss-" << endl
       << "              `.-//++o+/:/osssssso/:-.```-/+ssss:                   .ss. `.-:+ossso/--/osssso+ossso-" << endl
       << "           `-+osssyyyssssssss+:-.`   `-/oossssss-         `       .sh:        `.-:+ssssss+-.`/sss+- " << endl
       << "         ./ossyso/::ssssso/-.`        ```.+sssss-         `/` . .smo`              `-/osy+-.osss/`  " << endl
       << "       `/ossys/.`  /yss+-```.`           .+sssso-          .h:ysNh:`          `       `-/ossss+.    " << endl
       << "      -ossys/.    .oo/--:/+/.    ``.`    .osssso-     ``-:/+hNMMMs/.`   ``.-::-         -osso:`     " << endl
       << "    `/sssys:`    `:/++osss/..-:/+osss+-  -osssso-``.:/+osso+sNmN:-.--:/+ooss+:     `.-:/ssys+-      " << endl
       << "   .+sssss:     `.:osssssooosssssssssyo. -ssssss+ossssssssoos/:s:+osssssssssy/`.-/+ossssssssso-     " << endl
       << "  -ossssy+`       `/yssss:-/ossssssssso. :ssssso::+ossssso+sy:``/sssssossssss-`..-:+oyssssssss-     " << endl
       << " .oo///+y/      `./o+///o+-o+//oos///oo. /o///o+.:o+/+soo///s- -+//+s//o//+s+`    :o+/+oso//+s-  ```" << endl
       << "`/o/////oo:---:/++///////o+o///o/+///oo/+s+///++.++//o+/+///s::o+///+///+o+/.    .+///s/o////s/:+/-`" << endl
       << "-o+///////+++++//////////+y+///+//////+ooo////++:s///++/////++os//++o+/s+::-..`  :o///o+/////oos/.  " << endl
       << "-o////////////////////+++/s//////++//++:-+///+o//o//////+///+/-///+oo/+o+++++++/:/o//////o//+o/.    " << endl
       << "`:o/////////++o///++//-``.+o++++//o+/-` .+++o+-`:o+++//:+o+/.    ./+//+ss++////+s+o++++//+oo+.      " << endl
       << " `-//++++//:-/o+/:-``     `..``` ````    .:-.`  `...``  .-`      ```-+sy/:++////o/-...`  `..`       " << endl
       << "    ``````  -:.`                                                 `-+o+s//++/////o:`                 " << endl
       << "                                                               `:++//so++/////o+:`                  " << endl
       << "                                                               -s///////////o+:.                    " << endl
       << "                                                               -s////////+++-`                      " << endl
       << "                                                               .o/////+++:.                         " << endl
       << "                                                               .o//+++:.`                           " << endl
       << "                                                               -+o+:.`                              " << endl
       << "                                                               --`                                  " << endl;
  cout << endl << endl;
}

bool menu() {
  char choice;
  bool ready = false;
  
  while (!ready) {
    cout << "\033[2J\033[1;1H";
    masterpiece();
    cout << "1. Play Game" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. High scores" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "Enter choice (1-4): ";
    cin >> choice;
    switch (choice) {
    case '1':
      ready = true;
      return true;
      break;
    case '2':
      ready = false;
      instructions();
      break;
    case '3':
      ready = true;
      break;
    case '4':
      ready = true;
      break;
      return false;
    default:
      cout << "Invalid choice!" << endl;
    }
  }
}

void instructions() {
  string anythingReally;
  cout << "\033[2J\033[1;1H";
  cout << "The goal of Galaga is to survive as long as possible.  This is done by shooting at the enemy ships (big circles).  Your ship is a triangle, located at the bottom of the screen." << endl
       << "Move left with the left arrow key" << endl
       << "Move right with the right arrow key" << endl
       << "Shoot with the S key, located between the A and D key just in case you have not used a keyboard in awhile" << endl
       << "You die when the enemies (the big circles) reach you. You will die, it is inevitable.  But, it's not about when you die, it's about how.  Go down in flames of glory.  Take out 500 enemies for the one of you and earn your place in history alongside the likes of Alexander the Great and Optimus Prime." << endl
       << endl
       << "Now, go!" << endl << endl
       << "Press any key to return to menu";
  cin >> anythingReally;
  menu();
}
