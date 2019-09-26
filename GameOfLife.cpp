#include "GameOfLife.h"
#include <iostream>
#include <string>
#include "ArrayHelper.h"
#include <math.h>

using namespace std;

GameOfLife::GameOfLife()
{
  arrayHelper -> initializeGrid(theGrid,12,12);
  rowNum = 10;
  colNum = 10;
  arrayHelper -> fillGrid(theGrid,12,12);
  arrayHelper -> initializeGrid(secondGrid,12,12);
  arrayHelper -> fillGrid(secondGrid,12,12);
}
GameOfLife::GameOfLife(int n, int m)
{
  arrayHelper -> initializeGrid(theGrid,n+2,m+2);
  rowNum = n;
  colNum = m;
  arrayHelper -> fillGrid(theGrid,n+2,m+2);
  arrayHelper -> initializeGrid(secondGrid,n+2,m+2);
  arrayHelper -> fillGrid(secondGrid,n+2,m+2);
}
GameOfLife::GameOfLife(char** &newGrid, int n, int m)//works
{
  rowNum = n;
  colNum = m;
  theGrid = newGrid;
}
GameOfLife::~GameOfLife()
{
  //clean up both arrays
  arrayHelper -> deleteArray(theGrid,rowNum+2);
  arrayHelper -> deleteArray(secondGrid,rowNum+2);
  delete arrayHelper;
}
void GameOfLife::printCurrentGrid()
{
  arrayHelper -> printSelectGrid(theGrid,rowNum+1,colNum+1);
}
void GameOfLife::printSecondGrid()
{
  arrayHelper -> printSelectGrid(secondGrid,rowNum+1,colNum+1);
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
  arrayHelper -> initializeGrid(secondGrid,i,j);//works
  arrayHelper -> copyArray(theGrid,secondGrid,i,j);//works

}
//works
void GameOfLife::saveShadow()
{
  int i = (rowNum+2);
  int j = (colNum+2);
  arrayHelper -> copyArray(secondGrid,theGrid,i,j);

}
void GameOfLife::printFull()
{
  cout<< "Full Grid Debug:" <<endl;
  arrayHelper -> printGrid(theGrid,rowNum+2,colNum+2);
}
void GameOfLife::fillMirrorGrid()//works for corners and top and bottom need sides
{
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

void GameOfLife::fillDoughnutGrid()
{
  int rowCount = 0;
  for(int i =1;i<rowNum+1;i++)//handles the first row
  {
    rowCount ++;
    if(i==1)
    {
      for(int j = 1; j<colNum+1;++j)
      {
        char currentChar = theGrid[i][j];
        if(currentChar== 'X')
        {
          theGrid[rowNum+1][j] = 'X';
          if(j == 1)
          {
            theGrid[i][colNum+1] = 'X';
          }
          if(j == colNum)
          {
            theGrid[i][0] = 'X';
          }
        }
        else
        {
          theGrid[rowNum+1][j] = '-';
          if(j == 1)
          {
            theGrid[i][colNum+1] = '-';
          }
          if(j == colNum)
          {
            theGrid[i][0] = '-';
          }
        }
      }
    }
    else if(i == rowNum)
    {
      for(int j = 1; j<colNum+1;++j)
      {
        char currentChar = theGrid[i][j];
        if(currentChar== 'X')
        {
          theGrid[0][j] = 'X';
          if(j == 1)
          {
            theGrid[i][colNum+1] = 'X';
          }
          else if(j == colNum)
          {
            theGrid[i][0] = 'X';
          }
        }
        else
        {
          theGrid[0][j] = '-';
          if(j == 1)
          {
            theGrid[i][colNum+1] = '-';
          }
          else if(j == colNum)
          {
            theGrid[i][0] = '-';
          }
        }
      }
    }
    else
    {
      char firstColumnChar = theGrid[rowCount][1];
      char lastColumnChar = theGrid[rowCount][colNum];
      if(firstColumnChar == 'X')
        theGrid[rowCount][colNum+1] = 'X';
      else
        theGrid[rowCount][colNum+1] = '-';
      if(lastColumnChar == 'X')
        theGrid[rowCount][0] = 'X';
      else
        theGrid[rowCount][0] = '-';
    }
  }
}
void GameOfLife::createRandomPopulation(float density)//works
{
  srand(time(0));
  for(int i = 1; i< rowNum+1;++i)
  {
    float perRowCount = floor(float(colNum) * density);
    cout <<perRowCount<<endl;
    for(int j = 1;j<colNum+1;++j)
    {
      float randSelecter = float(rand())/float(RAND_MAX);
      if(randSelecter >=.5&&perRowCount >0)
      {
        theGrid[i][j] = 'X';
        perRowCount --;
      }
      else
        theGrid[i][j] = '-';
    }
  }
}
