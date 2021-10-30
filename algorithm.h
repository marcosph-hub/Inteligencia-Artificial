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
  std::pair<int,int> start;
  std::pair<int,int> destination;

  public:
  Algorithm(Board tableboard);

  
};