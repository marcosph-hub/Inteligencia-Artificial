#include "algorithm.h"

Algorithm::Algorithm(Board& tableboard) {
  /*
  for(int i = 0; i < tableboard.get_rows(); ++i){
    for(int j = 0; j < tableboard.get_columns(); ++j) {
      std::cout << "[" << tableboard.get_tableboard()[i][j].get_XCoord() << ","
      << tableboard.get_tableboard()[i][j].get_YCoord() << "]" << std::endl;
    }
  }
*/

  start = tableboard.get_start();
  destination = tableboard.get_destination();
  cost = 0;
//open_cells_list.push_back(start);
}

void Algorithm::A_Star(Cell current_cell) {
  open_cells_list.push_back(current_cell);
  if (is_destination(current_cell)) {
    //terminar
    std::cout << "final" << std::endl;
  } functions_update(current_cell);
}

bool Algorithm::is_destination(Cell cell_) {
  if (cell_ == destination){
    return true;
  } return false;
}

void Algorithm::functions_update(Cell current_cell) {
  cost = cost +1;

  //current_cell.set_Cost
}