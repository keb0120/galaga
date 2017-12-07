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
  bool collision(int, int, int);
  bool lose();
  void deleteElement(vector<int>&, int);
 private:
  int numships;
  vector<vector<int>> row_p;
  vector<vector<int>> xcoords;
  vector<vector<int>> ycoords;
  vector<vector<int>> hit;
  const int radius = 15;
  int separation = 70;
  const int xpos = 30;
  const int ypos = 30;
  };
