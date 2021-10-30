#pragma once

#include <iostream>
#include <vector>
#include <utility>


#include "cell.h"
#include "board.h"

class Algorithm {
  private:
  std::vector<Cell> open_cells_list;
  std::vector<Cell> close_cells_list;
  Cell start;
  Cell destination;
  int cost;

  public:
  Algorithm(Board& tableboard);
  void A_Star(Cell current_cell);
  bool is_destination(Cell cell_);
  void functions_update(Cell current_cell);
  
};