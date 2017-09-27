// Eric McCord-Snook
// December 2016

#include "BoardCell.h"

BoardCell::BoardCell() {
  val = 0;
  known = false;
}

BoardCell::BoardCell(int k) {
  val = k;
  known = true;
}

BoardCell::~BoardCell() {}
