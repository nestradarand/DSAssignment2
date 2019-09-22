#include "GameOfLife.h"
#include <iostream>
#include <string>


GameOfLife::GameOfLife()
{
  InitializeGrid(10,10);
  rowNum = 10;
  colNum = 10;
  fillInitialGrid();
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
void GameOfLife::printSecondGrid()
{
  for (int i = 0; i < rowNum; ++i) {   // for each row
    for (int j = 0; j < colNum; ++j) { // for each column
      std::cout << secondGrid[i][j];
    }
    std::cout << "\n";
  }
}
void GameOfLife::fillInitialGrid()
{
  for (int i = 0; i < rowNum; ++i)
  {   // for each row
    for (int j = 0; j < colNum; ++j)
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
    theGrid[numLine][i] = currentChar;
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
  for(int n = 0; n<rowNum;n++)
  {
    for(int m = 0;m<rowNum;m++)
    {
      int neighborNum = 0;
      if(theGrid[n-1][m-1] == 'x')
        neighborNum ++;
      if(theGrid[n-1][m] == 'x')
        neighborNum ++;
      if(theGrid[n-1][m+1] == 'x')
        neighborNum ++;
      if(theGrid[n][m-1] == 'x')
        neighborNum ++;
      if(theGrid[n][m+1] == 'x')
        neighborNum ++;
      if(theGrid[n+1][m-1] == 'x')
        neighborNum ++;
      if(theGrid[n+1][m] == 'x')
        neighborNum ++;
      if(theGrid[n+1][m+1] == 'x')
        neighborNum ++;
      if(neighborNum <= 1)
        secondGrid[n][m] = '-';
      else if(neighborNum == 3)
        secondGrid[n][m] = 'x';
      else if(neighborNum >=4)
        secondGrid[n][m] = '-';
    }
  }
  saveShadow();
}
void GameOfLife::makeShadowCopy()
{
  secondGrid =  new char*[rowNum];
  for(int i =0;i<colNum;i++)
    secondGrid[i] = new char[colNum];
  for (int i = 0; i < rowNum; ++i)
  {   // for each row
    for (int j = 0; j < colNum; ++j)
    { // for each column
      secondGrid[i][j] = theGrid[i][j];
    }
  }
}
void GameOfLife::saveShadow()
{
  for(int i = 0; i<rowNum;++i)
  {
    for(int j = 0;j<colNum;++j)
    {
      theGrid[i][j] = secondGrid[i][j];
    }
  }
}
