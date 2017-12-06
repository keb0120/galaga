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
    //gfx_circle(xpos + indices[i] * separation, ypos, radius);
    //xcoords.push_back(xpos + indices[i] * separation);// store x coord
    //ycoords.push_back(ypos); // store y coord
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
  //for (int j = row_p.size() - 1; j >= row_p.size() - 1; j++) {
    for (int i = 0; i < row_p[j].size(); i++) {
      //ycoords[i] += (*it)[i] * separation;
      ycoords[j][i] += separation;
      //gfx_circle(xcoords[i], ycoords[i], radius);
    }
  }
  // fill uppermost row with more circles
  newRow();
}

void Enemy::display()
{
  gfx_clear();
  
  //for (auto it = row_p.begin(); it != row_p.end(); it++) {
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
    cout << "first" << endl;
  }
  else {
    increment();
    display();
    cout << "next" << endl;
  }
}
