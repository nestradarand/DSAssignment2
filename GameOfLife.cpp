/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 2 Game Of Life
*/
//the following are included to help with array operations, random number generation and input outputs
#include "GameOfLife.h"
#include <iostream>
#include <string>
#include "ArrayHelper.h"
#include <math.h>

using namespace std;

/*NOTICE: many parameters have 2 spaces added to the row and column values in order
to account for the extra grid space surrounding the grid displayed to the user.
This extra "ring" around the main grid is used to avoid segmentation faults when
checking neighbors on the outer rims of the grid.  Moreover, it is used to implement
the mirror and doughnut modes.*/

//default constructor initializing default grid, secondGrid for shadow copies,
//and previous grid for stability detection
GameOfLife::GameOfLife()
{
  arrayHelper -> initializeGrid(theGrid,12,12);
  rowNum = 10;
  colNum = 10;
  arrayHelper -> fillGrid(theGrid,12,12);
  arrayHelper -> initializeGrid(secondGrid,12,12);
  arrayHelper -> fillGrid(secondGrid,12,12);
  arrayHelper -> initializeGrid(previousGrid,12,12);
  arrayHelper -> fillGrid(previousGrid,12,12);
}
//constructor taking dimensions for new grid and intitializes main grid, second grid,
// and previous grid reference
GameOfLife::GameOfLife(int n, int m)
{
  arrayHelper -> initializeGrid(theGrid,n+2,m+2);
  rowNum = n;
  colNum = m;
  arrayHelper -> fillGrid(theGrid,n+2,m+2);
  arrayHelper -> initializeGrid(secondGrid,n+2,m+2);
  arrayHelper -> fillGrid(secondGrid,n+2,m+2);
  arrayHelper -> initializeGrid(previousGrid,n+2,m+2);
  arrayHelper -> fillGrid(previousGrid,n+2,m+2);
}
//deconstructor deletes the arrayhelper object and deletes all member variables storing
//the main grid, the secondary grid, and the previous grid
GameOfLife::~GameOfLife()
{
  arrayHelper -> deleteArray(theGrid,rowNum+2);
  arrayHelper -> deleteArray(secondGrid,rowNum+2);
  arrayHelper -> deleteArray(previousGrid,rowNum+2);
  delete arrayHelper;
}
//prints the main grid, excludes the ring around the main grid
//thus the +1 parameters are used to ignore the first row and first column
void GameOfLife::printCurrentGrid()
{
  arrayHelper -> printSelectGrid(theGrid,rowNum+1,colNum+1);
}
//used for debugging, does the same as previous method but for the secondary grid
void GameOfLife::printSecondGrid()
{
  arrayHelper -> printSelectGrid(secondGrid,rowNum+1,colNum+1);
}
//used to fill the lines of the main grid
//needs to be used with for loop externally to work properly
//numline is a member variable to keep track of iterations
void GameOfLife::fillGridLine(std::string str)
{
  for(int i = 0; i <str.length();++i)
  {
    char currentChar = str[i];
    theGrid[numLine][i+1] = currentChar;
  }
  numLine ++;
}
/*this method calculates the next generation of the main grid
first a shadow copy is made then the contents of the main grid are copied
to the previous grid to help detect stability of the Population
Next all neighrbors are tested for and changes are made accordingly to the
second grid.  Then the second grid is saved back to the first grid*/
void GameOfLife::calculateNextGen()
{
  makeShadowCopy();
  if(checkNumber % 5 == 0)//every five iterations, a copy is made to reference stability
  {
    arrayHelper -> copyArray(theGrid,previousGrid,rowNum+2,colNum+2);
  }
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
  checkNumber ++;
}
//makes shadow copy of the main grid to the second grid
void GameOfLife::makeShadowCopy()
{
  int i = (rowNum+2);
  int j = (colNum+2);
  arrayHelper -> copyArray(theGrid,secondGrid,i,j);//works
}
//saves shadow copy to the main grid
void GameOfLife::saveShadow()
{
  int i = (rowNum+2);
  int j = (colNum+2);
  arrayHelper -> copyArray(secondGrid,theGrid,i,j);
}
//prints the full grid including the buffer ring; used for debugging
void GameOfLife::printFull()
{
  cout<< "Full Grid Debug:" <<endl;
  arrayHelper -> printGrid(theGrid,rowNum+2,colNum+2);
}
//populates the outer ring of the grid with the resulting cells from the mirror mode rules
void GameOfLife::fillMirrorGrid()
{
  int rowCount = 0;
  for(int i =1;i<rowNum+1;i++)
  {
    rowCount ++;
    if(i==1)//handles first row
    {
      for(int j = 1; j<colNum+2;++j)
      {
        char currentChar = theGrid[i][j];
        if(currentChar== 'X')
        {
          theGrid[i-1][j] = 'X';
          if(j == 1) //handles upper right corner
          {
            theGrid[i-1][j-1] = 'X';
            theGrid[i][j-1] = 'X';
          }
          if(j == colNum) //handles upper left corner
          {
            theGrid[i-1][j+1] = 'X';
            theGrid[i][j+1] = 'X';
          }
        }
        else //handles the event that there are no populated cells
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
    else if(i == rowNum) //handles last row
    {
      for(int j = 1; j<colNum+2;++j)
      {
        char currentChar = theGrid[i][j];
        if(currentChar== 'X')
        {
          theGrid[i+1][j] = 'X';
          if(j == 1) //handles upper left corner
          {
            theGrid[i][j-1] = 'X';
            theGrid[i+1][j-1] = 'X';
          }
          else if(j == colNum) //handles upper right corner
          {
            theGrid[i+1][j+1] = 'X';
            theGrid[i][j+1] = 'X';
          }
        }
        else//handles the event that the cells arent populated
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
    //for all rows in between the first and last, only the first and last cells
    //of each row are considered
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
//populates the outer buffer ring with the results of the doughnut rules
void GameOfLife::fillDoughnutGrid()
{
  int rowCount = 0;
  for(int i =1;i<rowNum+1;i++)
  {
    rowCount ++;
    if(i==1) //handles the first row
    {
      for(int j = 1; j<colNum+1;++j)
      {
        char currentChar = theGrid[i][j];
        if(currentChar== 'X')//if a cell is populated it fills the corresponding cell in the buffer
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
    else if(i == rowNum) //handles the last row
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
    //following statment handles all rows in between first and last
    //only looks at first and last entry on the main grid
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
//creates a random population in the main grid based on a given density
void GameOfLife::createRandomPopulation(float density)
{
  //set the seed for the random number
  srand(time(0));
  for(int i = 1; i< rowNum+1;++i)//for each row in the main grid
  {
    float perRowCount = floor(float(colNum) * density);//gets count for each row based on density
    for(int j = 1;j<colNum+1;++j)//iterates through each column
    {
      float randSelecter = float(rand())/float(RAND_MAX);
      if(randSelecter >=.5&&perRowCount >0)//randomly selects if cell gets populated
      {
        theGrid[i][j] = 'X';
        perRowCount --;//decrement row count so that a given row at most only has the desired density
      }
      else
        theGrid[i][j] = '-';
    }
  }
}
//checks if the main grid is equal to the generation from 5 iterations before
bool GameOfLife::checkStability()// returns false (0) if unstable
{
  return arrayHelper ->checkEquality(theGrid,previousGrid,rowNum+2,colNum+2);
}
//returns the main grid as a char** to be used outside of this class
char** GameOfLife::returnCurrentGrid()
{
  return theGrid;
}
