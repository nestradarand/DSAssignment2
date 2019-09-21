#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <iostream>


class GameOfLife
{
  int currentFillingLine = 0;
  char** theGrid;
  int rowNum = 0;
  int colNum =0;

public:
  GameOfLife();
  GameOfLife(int n,int m);
  ~GameOfLife();

  void printCurrentGrid();
  void fillInitialGrid();
  //works for individual lines
  void fillGridLine(std::string str);
  void resetMemberVars();
  //used for fillGriline to keep track of which line we are filling



private:
  void InitializeGrid(int n, int m);

};
#endif
