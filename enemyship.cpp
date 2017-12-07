#include "enemyship.h"
#include "gfx.h"
#include <stdio.h> // for NULL
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

Enemy::Enemy()
{
  // can put something in here later but for now don't really need anything  
}

Enemy::~Enemy()
{
}

void Enemy::newRow()
{
  numships = 0;
  numships = rand() % 7  + 1; // random number 1-10
  vector<int> indices; // has integers 1-7, will be shuffled
  vector<int> shortened; // will be stored the randomly generated indices
  vector<int> localxc; // xcoord of circle
  vector<int> localyc; // ycoord of circle
  
  for (int i = 0; i < 7; i++) { // vector filled with nums 1-7
    indices.push_back(i);
  }
  
  // randomize positions 
  random_shuffle(indices.begin(), indices.end());

  // store coords and index of first numships circles
  for (int i = 0; i < numships; i++) {    
    localxc.push_back(xpos + indices[i] * separation);
    localyc.push_back(ypos);
    shortened.push_back(indices[i]);
  }

  // store row of information
  row_p.push_back(shortened); // store whole row
  xcoords.push_back(localxc);
  ycoords.push_back(localyc);
}

void Enemy::increment()
{
  // move each row down one row
  for (int j  = 0; j < row_p.size(); j++) {
    for (int i = 0; i < row_p[j].size(); i++) {
      ycoords[j][i] += separation;
    }
  }
  // fill uppermost row with more circles
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

bool Enemy::lose()
{
  // y threshold: 649
  for (int j = 0; j < row_p.size(); j++) {
    for (int i = 0; i < row_p[j].size(); i++) {
      if (ycoords[j][i] + radius >= 550) {
	cout << "loooooozer" << endl;
	return true;
      }
    }
  }

  return false;
}

bool Enemy::collision(int xcenter, int ycenter, int rad)
{
  /* General algorithm:
     loop through rows
       loop through individual elements in row
         if (sqrt( (xcoord - xcenter)^2 + (ycoord - ycenter)^2 ) < radius+rad)
	   get rid of circle
	     1. destroy xcoord
	     2. destroy ycoord
  */

  for (int j = 0; j < row_p.size(); j++) {
    for (int i = 0; i < row_p[j].size(); i++) {
      if (sqrt( (xcoords[j][i] - xcenter)*(xcoord[j][i] - xcenter) +
		(ycoords[j][i] - ycenter)*(ycoord[j][i] - ycenter)) < (rad+radius))
      {
	xcoords[j].erase(xcoords[j].begin() + i);
	ycoords[j].erase(ycoords[j].begin() + i);
	return true;
      }
    }
  }
  return false;
}
