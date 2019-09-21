#include "GameOfLife.h"
#include <iostream>
#include <string>


GameOfLife::GameOfLife()
{
  InitializeGrid(10,10);
  rowNum = 10;
  colNum = 10;
}
GameOfLife::GameOfLife(int n, int m)
{
  InitializeGrid(n,m);
  rowNum = n;
  colNum = m;
}
GameOfLife::~GameOfLife()
{
  for(int i = 0; i< rowNum; ++ i)
    delete [] theGrid[i];
  delete [] theGrid;
}
void GameOfLife::InitializeGrid(int n, int m)
{
  theGrid = new char*[n];
  for(int i =0; i < m;++i)
    theGrid[i] = new char[m];
}
void GameOfLife::printCurrentGrid()
{
  for (int i = 0; i < rowNum; ++i) {   // for each row
    for (int j = 0; j < colNum; ++j) { // for each column
      std::cout << theGrid[i][j];
    }
    std::cout << "\n";
  }
}
void GameOfLife::fillInitialGrid()
{
  for (int i = 0; i < rowNum; ++i) {   // for each row
    for (int j = 0; j < colNum; ++j) { // for each column
      theGrid[i][j] = '-';
    }
  }
}
