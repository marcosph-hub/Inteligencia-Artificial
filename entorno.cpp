#define RED "\e[0;31m"
#define GRN "\e[0;92m"
#define NC "\e[0m"
#define YLW "\e[0;93m"
#include "entorno.h"

Board::Board() {
  rows = 22;    //para que sea 20 x 20 hay que añadir 2 filas y 2 col extras para señalizar los bordes 
  columns = 22;
  tableboard = new std::string*[rows];
  for (int iterator = 0; iterator < rows; iterator++) {
    tableboard[iterator] = new std::string[columns];
  }
  Create_Board();
}

Board::Board(int row_parameter, int col_parameter) {
  rows = row_parameter +2 ;
  columns = col_parameter +2;
  tableboard = new std::string*[rows];
  for (int iterator = 0; iterator < rows; iterator++) {
    tableboard[iterator] = new std::string[columns];
  }
  Create_Board();
}


Board::~Board(){
  for (int iterator = 0; iterator < rows; iterator++) {
    delete [] tableboard[iterator];
  }
  delete [] tableboard;
}

void Board::Create_Board() {
  for (int row_iterator = 0; row_iterator < rows; row_iterator++ ) {
    for (int col_iterator = 0; col_iterator < columns; col_iterator++) {
      if ((col_iterator == 0) || (col_iterator == columns -1)) {
        tableboard[row_iterator][col_iterator] = "|";
      } else if ((row_iterator == 0) && (col_iterator != 0)) {
        tableboard[row_iterator][col_iterator] = "*";
      } else if ((row_iterator == rows-1) && (col_iterator != columns -1)) {
        tableboard[row_iterator][col_iterator] = "*";
      } else {
        tableboard[row_iterator][col_iterator] = " ";
      }
    }
  }
}

void Board::FillByPercent(int percent) {
  int dimension = rows * columns;
  float fpercent = percent / 100.0;
  int n_obstacles = dimension * fpercent;

   for (int obst_iterator = 0; obst_iterator < n_obstacles; obst_iterator++) {
    int rand_row = rand() % (rows -1);
    int rand_col = rand() % (columns -1);
    for (int row_iterator = 1; row_iterator < rows -1; row_iterator++ ) {
      for (int col_iterator = 1; col_iterator < columns -1; col_iterator++) {
        if ((row_iterator == rand_row) && (col_iterator == rand_col)) {
          tableboard[rand_row][rand_col] = "O";
        }
      }
    }
  }
}


void Board::RandomFill() {
  srand (time(NULL));
  int total_cells = rows * columns;
  int nobstacles = rand() % total_cells;
  for (int obst_iterator = 0; obst_iterator < nobstacles; obst_iterator++) {
    int rand_row = rand() % (rows -1);
    int rand_col = rand() % (columns -1);
    for (int row_iterator = 1; row_iterator < rows -1; row_iterator++ ) {
      for (int col_iterator = 1; col_iterator < columns -1; col_iterator++) {
        if ((row_iterator == rand_row) && (col_iterator == rand_col)) {
          tableboard[rand_row][rand_col] = "O";
        }
      }
    }
  }
}

void Board::FillManual(int x, int y){
  if (tableboard[x][y] == " "){
    tableboard[x][y] = "0";
  }

}

void Board::RandomDestination() {
  int rand_row = 1 + rand() % (rows -2);
  int rand_col = 1 + rand() % (columns -2);
  tableboard[rand_row][rand_col] = "F";
}

void Board::ManualDestination(int x, int y){
  tableboard[x][y] = "F";
}

void Board::ManualInsertTaxi(int x, int y) {
  car.SetTaxiPlace(x,y);
}

void Board::RandomInsertTaxi(){
  srand(time(NULL));
  int rand_row;
  int rand_col;
  rand_row = 1 + rand() % (rows -2);
  rand_col = 1 + rand() % (columns -2);
  car.SetTaxiPlace(rand_row, rand_col);
}


void Board::Write() {
  for (int i=0; i < rows; i++){
    for (int j=0; j < columns; j++){
      if ((i == car.GetXCoord()) && (j == car.GetYCoord())) {
        std::cout << YLW << car.GetBody() << " ";
      } else if (tableboard[i][j] == "F") {
        std::cout << GRN << tableboard[i][j] << " ";
      } else {
        std::cout << NC << tableboard[i][j] << " ";
      }
    }
    std::cout << std::endl;
  }
}


/*
Board::Board(int option, std::string filename) { 
  rows = 22;    //para que sea 20 x 20 hay que añadir 2 filas y 2 col extras para señalizar los bordes 
  columns = 22;
  tableboard = new std::string*[rows];
  for (int iterator = 0; iterator < rows; iterator++) {
    tableboard[iterator] = new std::string[columns];
  }
  if (option == 2) {
    ManualFillBoard(filename);
  }
}
*/