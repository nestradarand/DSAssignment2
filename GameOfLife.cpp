#include "GameOfLife.h"
#include <iostream>
#include <string>
#include "ArrayHelper.h"

using namespace std;

GameOfLife::GameOfLife()
{
  arrayHelper -> initializeGrid(theGrid,12,12);
  rowNum = 10;
  colNum = 10;
  arrayHelper -> fillGrid(theGrid,12,12);
}
GameOfLife::GameOfLife(int n, int m)
{
  arrayHelper -> initializeGrid(theGrid,n+2,m+2);
  rowNum = n;
  colNum = m;
  arrayHelper -> fillGrid(theGrid,n+2,m+2);
}
GameOfLife::GameOfLife(char** &newGrid, int n, int m)
{
  arrayHelper -> initializeGrid(theGrid,n+2,m+2);
  rowNum = n;
  colNum = m;
  arrayHelper ->copyArray(newGrid,theGrid,n+2,m+2);
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
  delete arrayHelper;
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
  arrayHelper -> printSelectGrid(theGrid,rowNum+1,colNum+1);
}
void GameOfLife::printSecondGrid()
{
  arrayHelper -> printSelectGrid(secondGrid,rowNum+1,colNum+1);
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
  // secondGrid = new char*[i];
  // for(int p =0; p < i;++p)
  //   secondGrid[p] = new char[j];
  arrayHelper -> initializeGrid(secondGrid,i,j);//works
  arrayHelper -> copyArray(theGrid,secondGrid,i,j);//works
  // for (int i = 0; i < rowNum+2; ++i)
  // {   // for each row
  //   for (int j = 0; j < colNum+2; ++j)
  //   { // for each column
  //     secondGrid[i][j] = theGrid[i][j];
  //   }
  // }
}
//works
void GameOfLife::saveShadow()
{
  int i = (rowNum+2);
  int j = (colNum+2);
  arrayHelper -> copyArray(secondGrid,theGrid,i,j);
  // for(int i = 0; i<rowNum+2;++i)
  // {
  //   for(int j = 0;j<colNum+2;++j)
  //   {
  //     theGrid[i][j] = secondGrid[i][j];
  //   }
  // }
}
void GameOfLife::printFull()
{
  cout<< "Full Grid Debug:" <<endl;
  arrayHelper -> printGrid(theGrid,rowNum+2,colNum+2);
}
void GameOfLife::fillMirrorGrid()//works for corners and top and bottom need sides
{
  // theGrid[1][colNum+1] = 'X';//not sure why this is here
  int rowCount = 0;
  for(int i =1;i<rowNum+1;i++)//handles the first row
  {
    rowCount ++;
    if(i==1)
    {
      for(int j = 1; j<colNum+2;++j)
      {
        char currentChar = theGrid[i][j];
        if(currentChar== 'X')
        {
          theGrid[i-1][j] = 'X';
          if(j == 1)
          {
            theGrid[i-1][j-1] = 'X';
            theGrid[i][j-1] = 'X';
            continue;
          }
          if(j == colNum)
          {
            theGrid[i-1][j+1] = 'X';
            theGrid[i][j+1] = 'X';
          }
        }
        else
        {
          theGrid[i-1][j] = '-';
          if(j == 1)
          {
            theGrid[i-1][j-1] = '-';
            theGrid[i][j-1] = '-';
            continue;
          }
          if(j == colNum)
          {
            theGrid[i-1][j+1] = '-';
            theGrid[i][j+1] = '-';
          }
        }
      }
    }
    else if(i == rowNum)
    {
      for(int j = 1; j<colNum+2;++j)
      {
        char currentChar = theGrid[i][j];
        if(currentChar== 'X')
        {
          theGrid[i+1][j] = 'X';
          if(j == 1)
          {
            theGrid[i][j-1] = 'X';
            theGrid[i+1][j-1] = 'X';
          }
          else if(j == colNum)
          {
            theGrid[i+1][j+1] = 'X';
            theGrid[i][j+1] = 'X';
          }
        }
        else
        {
          theGrid[i+1][j] = '-';
          if(j == 1)
          {
            theGrid[i][j-1] = '-';
            theGrid[i+1][j-1] = '-';
          }
          else if(j == colNum)
          {
            theGrid[i+1][j+1] = '-';
            theGrid[i][j+1] = '-';
          }
        }
      }
    }
    else
    {
      char firstColumnChar = theGrid[rowCount][1];
      char lastColumnChar = theGrid[rowCount][colNum];
      if(firstColumnChar == 'X')
        theGrid[rowCount][0] = 'X';
      else
        theGrid[rowCount][0] = '-';
      if(lastColumnChar == 'X')
        theGrid[rowCount][colNum+1] = 'X';
      else
        theGrid[rowCount][colNum+1] = '-';
    }
  }
}
