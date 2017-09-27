// Eric McCord-Snook
// December 2016

#ifndef BOARDCELL_H
#define BOARDCELL_H

class BoardCell {
 public:
  BoardCell();
  BoardCell(int k);
  ~BoardCell();
  int val;
  bool known;
};

#endif
