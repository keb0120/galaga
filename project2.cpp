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
  vector<int> hit2;
  
  for (int i = 0; i < 7; i++) {
    indices.push_back(i);
  }
  
  
  random_shuffle(indices.begin(), indices.end());
  
  
  for (int i = 0; i < numships; i++) {
    
    
    hit2.push_back(1);
    localxc.push_back(xpos + indices[i] * separation);
    localyc.push_back(ypos);
    shortened.push_back(indices[i]);
  }
 hit.push_back(hit2);
  for(int j = 0; j < hit[0].size(); j++){
      cout << hit[0][j] << " ";

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
      if(hit[j][i] == 1)
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

bool Enemy::lose()
{
  
  for (int j = 0; j < row_p.size(); j++) {
    for (int i = 0; i < row_p[j].size(); i++) {
      if (ycoords[j][i] + radius >= 550 && hit[j][i] == 1) {
        cout << "loooooozer" << endl;
        //for (int k = 0; k < row_p.size(); k++) {
          //for (int l = 0; l < row_p[k].size(); l++) {
            //cout << hit[k][l] << " " ;
          //}
       // }
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
                (ycoords[j][i] - ycenter)*(ycoords[j][i] - ycenter)) < (rad+radius) && hit[j][i] == 1)
      {
        hit[j][i] = 0;
        //deleteElement(xcoords[j], i);
        //deleteElement(ycoords[j], i);
        //deleteElement(row_p[j], i);
        //(xcoords[j]).erase((xcoords[j]).begin() + i);
        //(ycoords[j]).erase((ycoords[j]).begin() + i);
        //row_p[j].erase(row_p[j].begin() + i);
       // display();
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
                                                                                       
