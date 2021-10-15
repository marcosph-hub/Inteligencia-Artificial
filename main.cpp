#include "entorno.h"

void FileData() {/*          <- EN CONSTRUCCION
  std::string filename;
  std::string row_file;
  std::string column_file;
  std::string taxi_file;
  std::string obstacles_file;
  std::cout << "Introduzca el nombre del fichero de configuración" << std::endl;
  std::cin >> filename;
  std::ifstream file(filename.c_str());
  if (!file.good()) {
    std::cerr << "Error en la apertura del fichero" << std::endl;
    exit(1);
  }
  getline(file,row_file);
  getline(file,column_file);
  int row = std::stoi(row_file);
  int columns = std::stoi(column_file);
  Board board(row,columns);

  getline(file, obstacles_file);
  int n_obstacles = stoi(obstacles_file);
  for(int iter_file = 0; iter_file < n_obstacles; iter_file++) {
    get
  }


  
  while(!file.eof()) {
std::cout << "chivatillo" << std::endl;
  }*/
}
int main () {
  //std::string filename = argv[1]; //usar mas tarde para evitar fallo 
  int option;
  int dim_option;
  int obst_option;
  int dest_option;
  int orig_option;
  int rows; 
  int columns;
  int percent;
  int xcoord;
  int ycoord;


  std::cout << "Elija como desea crear el Entorno: " << std::endl;
  std::cout << "(1) Por Fichero\n(2) Manual\n(0) Salir" << std::endl;
  std::cin >> option;

  if (option == 1) {
    FileData();
  } else {
      std::cout << "Elija como desea que sea las dimensiones del Entorno: " << std::endl;
      std::cout << "(1) Dimension por teclado\n(2) Dimenension Por Defecto" << std::endl;
      std::cin >> dim_option;


      switch (dim_option) {
      case 1: { //Entorno Manual
        std::cout << "Introduzca las dimensiones del entorno.\n Ancho del entorno (filas):\t"; 
        std::cin >> rows;
        std::cout << "Largo del entorno (columnas):\t";
        std::cin >> columns;
        Board manual_board(rows, columns);
        
        std::cout << "Elija como desea meter los obstaculos\n(1) Manual\n(2) Aleatorio" << std::endl;
        std::cin >> obst_option;
        if (obst_option == 1) { // Obstaculos Manuales mediante un % de obstaculos (más facil)
          std::cout << "Ponga el %(nº entero) de obstaculos que desea que haya\n" << std::endl;
          std::cin >> percent;
          manual_board.FillByPercent(percent);
        } else  {
          manual_board.RandomFill();
          std::cout << std::endl;
        }

        std::cout << "Elija como desea introducir el Destino\n(1) Destino Manual\n(2) Destino Aleatorio" << std::endl;
        std::cin >> dest_option;
        if (dest_option == 1) {
          std::cout << "Introduzca donde quiere que se encuentre el destino:\nIntroduzca la coordenada 'x': ";
          std::cin >> xcoord;
          std::cout << " y la coordenada 'y': ";
          std::cin >> ycoord;
          std::cout << std::endl;
          manual_board.ManualDestination(xcoord, ycoord);
        } else {
          manual_board.RandomDestination();
        }
        std::cout << "Elija como desea introducir el Origen:\n(1) Origen Manual\n(2) Origen Aleatorio" << std::endl;
        std::cin >> orig_option;
        if (orig_option == 1) {
          std::cout << "Introduzca donde quiere que se encuentre el origen:\nIntroduzca la coordenada 'x': ";
          std::cin >> xcoord;
          std::cout << " y la coordenada 'y': ";
          std::cin >> ycoord;
          std::cout << std::endl;
          manual_board.ManualInsertTaxi(xcoord, ycoord);
        } else {
          manual_board.RandomInsertTaxi();
        }
        manual_board.Write();
      }
      break;
    



      case 2: { 
        Board default_board;
        std::cout << "Elija como desea meter los obstaculos\n(1) Manual\n(2) Aleatorio" << std::endl;
        std::cin >> obst_option;
        if (obst_option == 1) { // Obstaculos Manuales mediante un % de obstaculos (más facil)
          std::cout << "Ponga el %(nº entero) de obstaculos que desea que haya\n" << std::endl;
          std::cin >> percent;
          default_board.FillByPercent(percent);
        } else  {
          default_board.RandomFill();
          std::cout << std::endl;
        }

        std::cout << "Elija como desea introducir el Destino\n(1) Destino Manual\n(2) Destino Aleatorio" << std::endl;
        std::cin >> dest_option;
        if (dest_option == 1) {
          std::cout << "Introduzca donde quiere que se encuentre el destino:\nIntroduzca la coordenada 'x': ";
          std::cin >> xcoord;
          std::cout << " y la coordenada 'y': ";
          std::cin >> ycoord;
          std::cout << std::endl;
          default_board.ManualDestination(xcoord, ycoord);

        } else {
          default_board.RandomDestination();
        }
        std::cout << "Elija como desea introducir el Origen:\n(1) Origen Manual\n(2) Origen Aleatorio" << std::endl;
        std::cin >> orig_option;
        if (orig_option == 1) {
          std::cout << "Introduzca donde quiere que se encuentre el origen:\nIntroduzca la coordenada 'x': ";
          std::cin >> xcoord;
          std::cout << " y la coordenada 'y': ";
          std::cin >> ycoord;
          std::cout << std::endl;
          default_board.ManualInsertTaxi(xcoord, ycoord);
        } else {
          default_board.RandomInsertTaxi();
        }
        default_board.Write();
      }
      break;
    }
  }
}

