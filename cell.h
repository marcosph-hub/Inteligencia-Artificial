#include <iostream>
#include <utility>

class Cell {

  private:
    char cell_value;
    bool open_cell;
    bool is_visited;
    std::pair<int,int> coordinates;
  
  public:
    Cell();
    Cell(char new_cell_value);
    ~Cell();

    char get_CellValue();
    bool get_OpenCell();
    bool get_IsVisited();
    std::pair<int,int> get_Coordinates();
    int get_XCoord();
    int get_YCoord();

    void set_CellValue(char parameter);
    void set_OpenCell(bool parameter);
    void set_IsVisited(bool parameter);
    void set_Coordinates(std::pair<int,int> param_coords);
    void set_XCoord(int x_param);
    void set_YCoord(int y_param);
    
    friend std::ostream& operator<<(std::ostream &os, Cell &cell_ );
    //friend std::ostream& operator<<(std::ostream &os, std::pair<int,int> &coord_pair);
    Cell& operator=(const Cell &cell_);
    bool operator==(const Cell &cell_)const;
};

