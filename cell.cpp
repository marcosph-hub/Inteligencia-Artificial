#include "cell.h"

Cell::Cell() {
  cell_value = ' ';
  open_cell = false;
  is_visited = false;
}

Cell::Cell(char new_cell_value) {
  cell_value = new_cell_value;
  open_cell = false;
  is_visited = false;
}

Cell::~Cell() {}

char Cell::get_CellValue() {
  return cell_value;
}

bool Cell::get_OpenCell() {
  return open_cell;
}

bool Cell::get_IsVisited() {
  return is_visited;
}

void Cell::set_CellValue(char parameter) {
  cell_value = parameter;
}

void Cell::set_OpenCell(bool parameter) {
  open_cell = parameter;
}

void Cell::set_IsVisited(bool parameter) {
  is_visited = parameter;
}


std::pair<int,int> Cell::get_Coordinates() {
  return coordinates;
}

int Cell::get_XCoord() {
  return coordinates.first;
}

int Cell::get_YCoord() {
  return coordinates.second;
}

void Cell::set_Coordinates(std::pair<int,int> param_coords) {
  coordinates = param_coords;
}

void Cell::set_XCoord(int x_param) {
  coordinates.first = x_param;
}

void Cell::set_YCoord(int y_param) {
  coordinates.second = y_param;
}

std::ostream& operator<<(std::ostream &os, Cell &cell_) {
  os << cell_.get_CellValue() << std::endl;
  return os;
}

Cell& Cell::operator=(const Cell &cell_) {
  this->cell_value = cell_.cell_value;
  this->is_visited = cell_.is_visited;
  this->open_cell = cell_.open_cell;
  return *this;
}

bool Cell::operator==(const Cell &cell_) const {
  if(this->cell_value == cell_.cell_value &&
    this->open_cell == cell_.open_cell &&
    this->is_visited == cell_.is_visited &&
    this->coordinates == cell_.coordinates) { return true; }
    return false;
}

/*
std::ostream& operator<<(std::ostream &os, std::pair<int,int> &coord_pair) {
  os << "[" << coord_pair.first << "," << coord_pair.second << "]" << std::endl;
  return os;
}
*/