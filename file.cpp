#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
/**
 * 
 * FICHERO DE PRUEBA
 * 
 **/
int main (int argc, char* argv[]) {
  int row_file, column_file
  std::string coord;
  std::ifstream file(argv[1]);
  if (!file.good()) {
    std::cerr << "Error en la apertura del fichero" << std::endl;
    exit(1);
  }
  getline(file,row_file);
  getline(file,column_file);
  int row = std::stoi(row_file);
  int columns = std::stoi(column_file);

  for (int i=0; i < 4; i++) {
     getline(file, coord);
     std::cout << "[" << coord << "]" << std::endl;
  }

}
