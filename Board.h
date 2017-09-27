// Eric McCord-Snook
// December 2016

#ifndef BOARD_H
#define BOARD_H

#include "BoardCell.h"

class Board {
 public:
  Board();
  ~Board();
  void print();
  BoardCell cells[9][9];
};

#endif
