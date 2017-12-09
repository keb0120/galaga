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
  bool lose(const char*, const char*);
  void deleteElement(vector<int>&, int);
  void dispVector(vector<vector<int>> &);
 private:
  int numships;
  const int radius = 15;
  const int separation = 70;
  const int xpos = 30;
  const int ypos = 30;
};
