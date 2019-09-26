#include "GameOfLife.h"
#include <iostream>
#include <string>


GameOfLife::GameOfLife()
{
  InitializeGrid(10,10);
  rowNum = 10;
  colNum = 10;
  fillInitialGrid();
  makeShadowCopy();
}
GameOfLife::GameOfLife(int n, int m)
{
  InitializeGrid(n,m);
  rowNum = n;
  colNum = m;
  fillInitialGrid();
  makeShadowCopy();
}

GameOfLife::~GameOfLife()
{
  //clean up both arrays
  for(int i = 0; i< rowNum; ++ i)
    delete [] theGrid[i];
  delete [] theGrid;
  for(int i = 0; i< rowNum; ++ i)
    delete [] secondGrid[i];
  delete [] secondGrid;
}
void GameOfLife::InitializeGrid(int n, int m)
{
  int i = (n+2);
  int j = (m+2);
  theGrid = new char*[i];
  for(int p =0; p < i;++p)
    theGrid[p] = new char[j];
}
void GameOfLife::printCurrentGrid()
{
  for (int i = 1; i < rowNum+1; ++i) {   // for each row
    for (int j = 1; j < colNum+1; ++j) { // for each column
      std::cout << theGrid[i][j];
    }
    std::cout << "\n";
  }
}
void GameOfLife::printSecondGrid()
{
  for (int i = 0; i < rowNum+2; ++i) {   // for each row
    for (int j = 0; j < colNum+2; ++j) { // for each column
      std::cout << secondGrid[i][j];
    }
    std::cout << "\n";
  }
}
void GameOfLife::fillInitialGrid()
{
  for (int i = 0; i < rowNum+2; ++i)
  {   // for each row
    for (int j = 0; j < colNum+2; ++j)
    { // for each column
      theGrid[i][j] = '-';
    }
  }
}
void GameOfLife::fillGridLine(std::string str)
{
  for(int i = 0; i <str.length();++i)
  {
    char currentChar = str[i];
    theGrid[numLine][i+1] = currentChar;
  }
  numLine ++;
}
void GameOfLife::resetMemberVars()
{
  int numLine = 0;
  int rowNum = 0;
  int colNum =0;
}
void GameOfLife::calculateNextGen()
{
  makeShadowCopy();
  //segmentation fault in here somehow
  for(int n = 1; n<rowNum+1;++n)
  {
    for(int m = 1;m<colNum+1;++m)
    {
      int neighborNum = 0;

      if(theGrid[n-1][m-1] == 'X')
        neighborNum ++;
      if(theGrid[n-1][m] == 'X')
        neighborNum ++;
      if(theGrid[n-1][m+1] == 'X')
        neighborNum ++;
      if(theGrid[n][m-1] == 'X')
        neighborNum ++;
      if(theGrid[n][m+1] == 'X')
        neighborNum ++;
      if(theGrid[n+1][m-1] == 'X')
        neighborNum ++;
      if(theGrid[n+1][m] == 'X')
        neighborNum ++;
      if(theGrid[n+1][m+1] == 'X')
        neighborNum ++;
      if(neighborNum <= 1)
        secondGrid[n][m] = '-';
      if(neighborNum == 3)
        secondGrid[n][m] = 'X';
      if(neighborNum >=4)
        secondGrid[n][m] = '-';
    }
  }
  saveShadow();
}
//works
void GameOfLife::makeShadowCopy()
{
  int i = (rowNum+2);
  int j = (colNum+2);
  secondGrid = new char*[i];
  for(int p =0; p < i;++p)
    secondGrid[p] = new char[j];
  for (int i = 0; i < rowNum+2; ++i)
  {   // for each row
    for (int j = 0; j < colNum+2; ++j)
    { // for each column
      secondGrid[i][j] = theGrid[i][j];
    }
  }
}
//works
void GameOfLife::saveShadow()
{
  for(int i = 0; i<rowNum+2;++i)
  {
    for(int j = 0;j<colNum+2;++j)
    {
      theGrid[i][j] = secondGrid[i][j];
    }
  }
}
void GameOfLife::printFull()
{
  for (int i = 0; i < rowNum+2; ++i) {   // for each row
    for (int j = 0; j < colNum+2; ++j) { // for each column
      std::cout << theGrid[i][j];
    }
    std::cout << "\n";
  }
}
