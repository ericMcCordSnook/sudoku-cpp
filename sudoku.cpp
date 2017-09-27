// Eric McCord-Snook
// December 2016

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Board.h"

using namespace std;

bool checkValidValueChange(Board * b, int r, int c) {
  int val = b->cells[r][c].val;
  
  // check row
  for(int i = 0; i < 9; i++) {
    if(i==c) {continue;}
    if(val == b->cells[r][i].val) {return false;}
  }
  
  // check column
  for(int i = 0; i < 9; i++) {
    if(i==r) {continue;}
    if(val == b->cells[i][c].val) {return false;}
  }
  
  // check subgrid
  int rInitial = r - (r % 3);
  int cInitial = c - (c % 3);
  for(int i = rInitial; i < rInitial + 3; i++) {
    for(int j = cInitial; j < cInitial + 3; j++) {
      if(i == r && j == c) {continue;}
      if(val == b->cells[i][j].val) {return false;}
    }
  }

  // return true if all checks pass
  return true;
}

bool checkValidBoard(Board * b) {
  bool taken[10];
  for(int i = 0; i < 10; i++) {taken[i] = false;}

  // check rows
  for(int r = 0; r < 9; r++) {
    for(int c = 0; c < 9; c++) {
      int val = b->cells[r][c].val;
      if(val == 0) {continue;}
      if(taken[val]) {return false;}
      taken[val] = true;
    }
    for(int i = 0; i < 10; i++) {taken[i] = false;}
  }
  
  // check columns
  for(int c = 0; c < 9; c++) {
    for(int r = 0; r < 9; r++) {
      int val = b->cells[r][c].val;
      if(val == 0) {continue;}
      if(taken[val]) {return false;}
      taken[val] = true;
    }
    for(int i = 0; i < 10; i++) {taken[i] = false;}
  }

  // check subgrids
  for(int gridNum = 0; gridNum < 9; gridNum++) {
    int rInit = gridNum - (gridNum % 3);
    int cInit = 3 * (gridNum % 3);
    for(int r = rInit; r < rInit + 3; r++) {
      for(int c = cInit; c < cInit + 3; c++) {
	int val = b->cells[r][c].val;
	if(val == 0) {continue;}
	if(taken[val]) {return false;}
	taken[val] = true;
      }
    }
    for(int i = 0; i < 10; i++) {taken[i] = false;}
  }

  // return true if all checks pass
  return true;
}

Board * backtrackSolve(Board * b) {
  // spotNum is a number representing where on the board we are
  // looking, starting at 0 as the upper left corner, and 80
  // as the lower right corner, since there 81 spots total
  int spotNum = 0;

  while(spotNum < 81) {
    int r = spotNum / 9;
    int c = spotNum % 9;
    if(b->cells[r][c].known) {
      spotNum++;
      continue;
    }
    b->cells[r][c].val = 1;
    while(b->cells[r][c].val > 9 || !checkValidValueChange(b, r, c)) {
      if(b->cells[r][c].val < 9) {
	b->cells[r][c].val++;
      } else {
	b->cells[r][c].val = 0;
	spotNum--;
	r = spotNum / 9;
	c = spotNum % 9;
	while(b->cells[r][c].known) {
	  spotNum--;
	  r = spotNum / 9;
	  c = spotNum % 9;
	}
	b->cells[r][c].val++;
      }
    }
    spotNum++;
  }
  return b;
}

int main(int argc, char** argv) {
  if(argc != 2) {
    cout << "Need a file name as a parameter." << endl;
    exit(1);
  }
  ifstream file(argv[1], ifstream::binary);
  if(!file.is_open()) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
  }
  Board *b = new Board();
  for(int r = 0; r < 9; r++) {
    string line;
    file >> line;
    for(int c = 0; c < 9; c++) {
      int cur = stoi(line.substr(c,1));
      if(cur != 0) {
	b->cells[r][c].val = cur;
	b->cells[r][c].known = true;
      }
    }
  }
  file.close();
  cout << endl << "Starting board: " << endl;
  b->print();
  b = backtrackSolve(b);
  cout << endl << "Completed board: " << endl;
  b->print();
  if(checkValidBoard(b)) {
    cout << "Board is valid!" << endl;
  }
  delete b;
  return 0;
}
