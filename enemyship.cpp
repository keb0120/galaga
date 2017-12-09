#include "enemyship.h"
#include "gfxnew.h"
#include <stdio.h> // for NULL
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> xcoords;
vector<vector<int>> ycoords;
vector<vector<int>> row_p;

Enemy::Enemy()
{
 
}

Enemy::~Enemy()
{
}

void Enemy::newRow()
{ 
  numships = 0;
  numships = rand() % 7  + 1;
  vector<int> indices; 
  vector<int> shortened;
  vector<int> localxc;
  vector<int> localyc;
  
  for (int i = 0; i < 7; i++) {
    indices.push_back(i);
  }
  
  
  random_shuffle(indices.begin(), indices.end());
  
  
  for (int i = 0; i < numships; i++) {
    localxc.push_back(xpos + indices[i] * separation);
    localyc.push_back(ypos);
    shortened.push_back(indices[i]);
  }
  
  row_p.push_back(shortened);
  xcoords.push_back(localxc);
  ycoords.push_back(localyc);
}

void Enemy::increment()
{

  for (int j  = 0; j < row_p.size(); j++) {
    for (int i = 0; i < row_p[j].size(); i++) {
      ycoords[j][i] += separation;
    }
  }

  newRow();
}

void Enemy::display()
{
  gfx_clear();

  for (int j = 0; j < row_p.size(); j++) {
    for (int i = 0; i < row_p[j].size(); i++) {
      gfx_circle(xcoords[j][i], ycoords[j][i], radius);
    }
  }
  gfx_flush();
}

void Enemy::play()
{
  if (row_p.size() == 0) {
    newRow();
    display();
  }
  
  else {
    increment();
    display();
  }
}

bool Enemy::lose(const char * hits, const char * rounds)
{
  
  for (int j = 0; j < row_p.size(); j++) {
    for (int i = 0; i < row_p[j].size(); i++) {
      if (ycoords[j][i] + radius >= 550) {
        gfx_clear();
	gfx_text(200, 200, "You lose!");
	gfx_text(200, 215, "Score: ");
	gfx_text(300, 215, hits);
	gfx_text(200, 230, "Rounds: ");
	gfx_text(300, 230, rounds);
        return true;
	
      }
    }
  }
  
  return false;
}

bool Enemy::collision(int xcenter, int ycenter, int rad)
{
  for (int j = 0; j < row_p.size(); j++) {
    for (int i = 0; i < row_p[j].size(); i++) {
      if (sqrt( (xcoords[j][i] - xcenter)*(xcoords[j][i] - xcenter) +
                (ycoords[j][i] - ycenter)*(ycoords[j][i] - ycenter)) < (rad+radius))
      {
        deleteElement(xcoords[j], i);
        deleteElement(ycoords[j], i);
        deleteElement(row_p[j], i);
	display();
	return true;
      }
    }
  }
  return false;
}

void Enemy::deleteElement(vector<int>& temp, int col)
{
  temp.erase(temp.begin()+col);
}       

void Enemy::dispVector(vector<vector<int>>& temp)
{
  for (int i = 0; i < temp.size(); i++) {
    for (int j = 0; j < temp[i].size(); j++) {
      cout << temp[i][j] << " ";
    }
    cout << endl;
  }
}
