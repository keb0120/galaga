#include <vector>
#include "gfx.h"
using namespace std;
class Enemy {
 public:
  Enemy();
  ~Enemy();
  void destroy(bool);
  void increment();
  void newRow();
  void play();
  void display();
 private:
  int numships;
  vector<vector<int>> row_p;
  //vector<int> xcoords;
  //vector<int> ycoords;
  vector<vector<int>> xcoords;
  vector<vector<int>> ycoords;
  const int radius = 15;
  int separation = 70;
  const int xpos = 30;
  const int ypos = 30;
};
