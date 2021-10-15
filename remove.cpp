#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <fstream>
#include <algorithm>

/**
 * 
 * FICHERO DE PRUEBA
 * 
 **/

int main (){
  std::string filename;
  std::string data;
  std::cout << "nombre del fichero:" << std::endl;
  std::cin >> filename;
  std::ifstream file(filename.c_str());
  if (!file.good()) {
    std::cerr << "Error en la apertura del fichero" << std::endl;
    exit(1);
  }
  for(int i=0; i<8; i++) {
    getline(file,data);
    //remove(data.begin(), data.end(), ' ');
    //data.erase(std::remove(data.begin(), data.end(), std::isspace), data.end());
    std::cout << data[0] << data[2] << std::endl;
    char a = data[0];
    int ia = a - '0';
    std::cout << ia << std::endl;
    
  }
}
