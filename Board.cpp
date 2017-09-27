// Eric McCord-Snook
// December 2016

#include <iostream>
#include "Board.h"
using namespace std;

Board::Board() {}

Board::~Board() {}

void Board::print() {
  cout << endl;
  for(int r = 0; r < 9; r++) {
    for(int c = 0; c < 9; c++) {
      int cur = cells[r][c].val;
      if (cur != 0) { cout << cur; }
      else { cout << " "; }
      if(c == 2 || c == 5) { cout << " | "; }
      else if (c != 8) { cout << " "; }
      else { cout << endl; }
    }
    if(r == 2 || r == 5) { cout << "------+-------+------" << endl; }
  }
  cout << endl;
}
