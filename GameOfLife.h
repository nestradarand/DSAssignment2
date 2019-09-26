#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <iostream>


class GameOfLife
{
  int numLine = 1;
  char** theGrid;
  char** secondGrid;
  int rowNum = 0;
  int colNum =0;

public:
  GameOfLife();
  GameOfLife(int n,int m);
  ~GameOfLife();

  void printCurrentGrid();
  void printSecondGrid();
  void fillInitialGrid();
  //works for individual lines
  void fillGridLine(std::string str);
  void resetMemberVars();
  void calculateNextGen();

  void makeShadowCopy();

  void printFull();//for debugging to vew buffer





private:
  void InitializeGrid(int n, int m);
  void saveShadow();

};
#endif
