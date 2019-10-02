/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 2 Game Of Life
*/
#include "ArrayHelper.h"
#include <iostream>
#include <string>

using namespace std;

//both constructor and deconstructor are emtpy due to lack of member variables
ArrayHelper::ArrayHelper(){}
ArrayHelper::~ArrayHelper(){}

//deletes given array passed by reference
void ArrayHelper::deleteArray(char** toDelete, int length)
{
  //delete each pointer to an array
  for(int i = 0; i< length; ++i)
  {
    delete [] toDelete[i];
  }
  //delete the array of pointers
  delete [] toDelete;
}
//copies first inputted array to second one; requires dimensions to run properly
void ArrayHelper::copyArray(char** initArray,char** &copyArray,int n,int m)
{
  for(int i = 0; i<n;++i)
  {
    for(int j = 0;j<m;++j)
    {
      copyArray[i][j] = initArray[i][j];
    }
  }
}
//prints a grid based on the given parameters for length and width
void ArrayHelper::printGrid(char** &theArray, int n,int m)
{
  for(int i =0;i <n;++i)
  {
    for(int j=0;j<m;++j)
      cout<<theArray[i][j];
    cout << "\n";
  }
}
//prints only the main grid; specialized for the game of life
void ArrayHelper::printSelectGrid(char** &theArray, int n,int m)
{
  //index begins at one to ignore the buffer ring for the grid
  for(int i =1;i <n;++i)
  {
    for(int j=1;j<m;++j)
      cout<<theArray[i][j];
    cout << "\n";
  }
}
//initializes a given 2d grid based on the dimensions given
void ArrayHelper::initializeGrid(char** &newArray,int n, int m)
{
  newArray = new char*[n];
  for(int i = 0; i<n;++i)
  {
    newArray[i] = new char[m];
  }
}
//fills initial grid with '-' for given dimensions
void ArrayHelper::fillGrid(char** &grid,int n, int m)
{
  for (int i = 0; i < n; ++i) {   // for each row
    for (int j = 0; j < m; ++j) { // for each column
      grid[i][j] = '-';
    }
  }
}

//Assuming both grids have same dimensions, contents are checked for each grid to check equality
bool ArrayHelper::checkEquality(char** firstGrid, char** secondGrid,int n,int m)
{
  for(int i =1;i<n;++i)
  {
    for(int j = 0; j<m;++j)
    {
      if(firstGrid[i][j] != secondGrid[i][j])
        return false;
    }
  }
  return true;
}
