#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <sstream>
#include <vector>
/**
 * 
 * FICHERO DE PRUEBA
 * 
 **/
int main (int argc, char* argv[]) {

  int row_file, column_file;
  std::string coord;
  std::ifstream file(argv[1]);
  if (!file.good()) {
    std::cerr << "Error en la apertura del fichero" << std::endl;
    exit(1);
  }
  /*
  getline(file,row_file);
  getline(file,column_file);
  int row = std::stoi(row_file);
  int columns = std::stoi(column_file);

  for (int i=0; i < 4; i++) {
     getline(file, coord);
     std::cout << "[" << coord << "]" << std::endl;
  }
*/
int a,b;
std::string mystr;
/*
getline(file,mystr);
std::stringstream(mystr) >> a;
std::cout << "Resultado: " << a << std::endl;*/

//while(!file.eof()) {
  getline(file,mystr);
  /*std::cout << "pre string stream: " << mystr << std::endl;
  std::stringstream(mystr) >> a;
  std::cout << "post string stream: " << mystr << std::endl;
  std::stringstream(mystr) >> b;
  std::cout << "fila:  " << a << " columna: " << b << std::endl;*/
  std::istringstream ss(mystr);
  std::vector<int> v;
while(ss >> a) {
  v.push_back(a);
  //std::cout << a << std::endl;
}
row_file = v[0];
column_file = v[1];
std::cout << "[" << row_file << " " << column_file << "]" << std::endl;
//}

}
