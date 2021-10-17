#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include <fstream>
#include <sstream>
#include <vector>

#include "taxi.h"

class Board {
  private:
    std::string **tableboard;
    Taxi car;
    int rows;
    int columns;
  
  public:
    Board();
    Board(int row_parameter, int col_parameter);
    ~Board();
    void Create_Board();
    void Write();
    void RandomFill();
    void FillByPercent(int percent);
    void FillManual(int x, int y);
    void RandomDestination();
    void ManualDestination(int x, int y);
    void ManualInsertTaxi(int x, int y);
    void RandomInsertTaxi();

};
