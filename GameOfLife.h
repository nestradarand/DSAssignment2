#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <iostream>


class GameOfLife
{
public:
  GameOfLife();
  GameOfLife(int n,int m);
  ~GameOfLife();

  void printCurrentGrid();
  void fillInitialGrid();

  char** theGrid;
  int rowNum;
  int colNum;


private:
  void InitializeGrid(int n, int m);

};
#endif
