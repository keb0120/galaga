#include "othello.h"
#include <iostream>

using namespace std;

Othello::Othello()
{
  for (int x = 0; x < BOARD_SIZE; x++) {
    for (int y = 0; y < BOARD_SIZE; y++) {
      if (x == BOARD_SIZE / 2) {
	if (y == BOARD_SIZE / 2)
	  board[x][y] = 'X';
	else if (y == BOARD_SIZE / 2 + 1)
	  board[x][y] = 'O';
      }
      else if (x == BOARD_SIZE / 2 + 1) {
	if (y == BOARD_SIZE / 2) 
	  board[x][y] = 'O';
        else if (y == BOARD_SIZE / 2 + 1)
	  board[x][y] = 'X';
      }
    }
  }
}

Othello::~Othello()
{ }

void Othello::dispBoard()
{
  cout << " ";
  for (int i = 0; i < BOARD_SIZE; i++)
    cout << i;
  
  for (int x = 0; x < BOARD_SIZE; x++) {
    cout << x;
    for (int y = 0; y < BOARD_SIZE; y++) {
      cout << board[x][y];
    }
    cout << endl;
  }
}

void Othello::checkValid(int x, int y)
{
  tempx = x;
  tempy = y;
  while (x < 0 || x > BOARD_SIZE || y < 0 || y > BOARD_SIZE) {
    cout << "Invalid input, try again: ";
    cin >> tempx >> tempy;
  }

  boardx = tempx;
  boardy = tempy;
}
    

	
